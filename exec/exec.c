/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 22:19:41 by lray              #+#    #+#             */
/*   Updated: 2023/10/28 13:46:35 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static t_env	*make_env(t_dyntree *root, t_ctx *ctx, int pipe_in, int pipe_out);
static t_env	*set_env_cmd(t_env *env ,t_dyntree *root, t_ctx *ctx, int pipe_in, int pipe_out);
static t_env	*set_env_builtins(t_env *env, t_dyntree *root, t_ctx *ctx, int pipe_in, int pipe_out);
static t_env	*set_env_redirection(t_env *env, t_dyntree *root, t_ctx *ctx, int pipe_in, int pipe_out);
static int		exec_env(t_ctx *ctx, t_env *env, pid_t *pid, int **pipes_list, int nbr_pipes);
static t_env	*select_fd(t_env *env);
static void		run_cmd(t_env *env, t_grpvar *grpvar);
static void		run_builtins(t_env *env, t_ctx *ctx);
static pid_t	*make_pids(pid_t *pids, int num_pids);
static void		wait_all(pid_t *pids, int num_cmd);
static void		close_unused_pipes(int **pipes_list, int nbr_pipes, int pipe_in, int pipe_out);

int	exec(t_ctx *ctx)
{
	size_t	i_child;
	int		**pipes_list;
	t_env	*env;
	pid_t	*pids;

	pids = NULL;
	env = NULL;
	pipes_list = NULL;
	i_child = 0;
	if (ctx->tree->type == TK_PIPE)
	{
		pipes_list = pipes_list_create((int)ctx->tree->numChildren - 1);
		pids = make_pids(pids, (int)ctx->tree->numChildren);
		while (i_child < ctx->tree->numChildren)
		{
			if (i_child == 0)
				env = make_env(ctx->tree->children[i_child], ctx, -1, pipes_list[i_child][1]);
			else if ((int)i_child == (int)ctx->tree->numChildren - 1)
				env = make_env(ctx->tree->children[i_child], ctx, pipes_list[(int)i_child - 1][0], -1);
			else
				env = make_env(ctx->tree->children[i_child], ctx, pipes_list[(int)i_child - 1][0], pipes_list[i_child][1]);
			if (env == NULL)
			{
				++i_child;
				continue ;
			}
			exec_env(ctx, env, &pids[i_child], pipes_list, (int)ctx->tree->numChildren - 1);
			env_free(env);
			++i_child;
		}
		wait_all(pids, ctx->tree->numChildren);
		free(pids);
		pipes_list_free(pipes_list, (int)ctx->tree->numChildren -1);
	}
	else
	{
		pids = make_pids(pids, 1);
		env = make_env(ctx->tree, ctx, -1, -1);
		if (env == NULL)
		{
			free(pids);
			return (0);
		}
		exec_env(ctx, env, &pids[0], NULL, 0);
		wait_all(pids, 1);
		env_free(env);
		free(pids);
	}
	return (1);
}

static t_env	*make_env(t_dyntree *root, t_ctx *ctx, int pipe_in, int pipe_out)
{
	t_env	*env;

	env = env_new();
	if (root->type == TK_COMMAND)
		env = set_env_cmd(env, root, ctx, pipe_in, pipe_out);
	else if (root->type == TK_BUILTINS)
		env = set_env_builtins(env, root, ctx, pipe_in, pipe_out);
	else if (root->type == TK_REDIRECTION)
		env = set_env_redirection(env, root, ctx, pipe_in, pipe_out);
	if (env == NULL)
		return (NULL);
	return (env);
}

static t_env	*set_env_cmd(t_env *env ,t_dyntree *root, t_ctx *ctx, int pipe_in, int pipe_out)
{
	t_dynarrstr	*argv;

	argv = NULL;
	env->type = TK_COMMAND;
	env->path = get_cmd_path(root->value, ctx->grpvar);
	if (!env->path)
	{
		ft_puterror("command not found");
		env_free(env);
		return (NULL);
	}
	argv = make_argv(root);
	if (!argv)
	{
		env_free(env);
		return(NULL);
	}
	env->args = arrcpy(argv->array, (int)argv->size);
	dynarrstr_free(argv);
	env->fd_in = get_infd(root, ctx);
	env->fd_out = get_outfd(root);
	env->pipe_in = pipe_in;
	env->pipe_out = pipe_out;
	return (env);
}

static t_env	*set_env_builtins(t_env *env, t_dyntree *root, t_ctx *ctx, int pipe_in, int pipe_out)
{
	t_dynarrstr	*argv;

	argv = NULL;
	env->type = TK_BUILTINS;
	env->path = ft_strdup(root->value);
	argv = make_argv(root);
	if (!argv)
	{
		env_free(env);
		return(NULL);
	}
	env->args = arrcpy(argv->array, (int)argv->size);
	dynarrstr_free(argv);
	env->fd_in = get_infd(root, ctx);
	env->fd_out = get_outfd(root);
	env->pipe_in = pipe_in;
	env->pipe_out = pipe_out;
	return (env);
}

static t_env	*set_env_redirection(t_env *env, t_dyntree *root, t_ctx *ctx, int pipe_in, int pipe_out)
{
	env->type = TK_REDIRECTION;
	env->path = NULL;
	env->args = NULL;
	env->fd_in = get_infd(root, ctx);
	env->fd_out = get_outfd(root);
	env->pipe_in = pipe_in;
	env->pipe_out = pipe_out;
	return (env);
}

static int	exec_env(t_ctx *ctx, t_env *env, pid_t *pid, int **pipes_list, int nbr_pipes)
{
	int	bk_stdin;
	int	bk_stdout;
	(void)	pipes_list;
	(void)	nbr_pipes;

	env = select_fd(env);
	if (env->type == TK_COMMAND)
	{
		*pid = fork();
		if (*pid == 0)
		{
			if (pipes_list)
				close_unused_pipes(pipes_list, nbr_pipes, env->pipe_in, env->pipe_out);
			dup2(env->fd_in, STDIN_FILENO);
			dup2(env->fd_out, STDOUT_FILENO);
			run_cmd(env, ctx->grpvar);
		}
		else if (*pid > 0)
		{
			if (env->fd_in != 0)
				close(env->fd_in);
			if (env->fd_out != 1)
				close(env->fd_out);
		}
		else
		{
			perror("minishel");
			return (0);
		}
	}
	else if (env->type == TK_BUILTINS)
	{

		if (env->pipe_in != -1)
		{
			bk_stdin = dup(STDIN_FILENO);
			dup2(env->pipe_in, STDIN_FILENO);
			close(env->pipe_in);
		}
		if (env->pipe_out != -1)
		{
			bk_stdout = dup(STDOUT_FILENO);
			dup2(env->pipe_out, STDOUT_FILENO);
			close(env->pipe_out);
		}
		run_builtins(env, ctx);
		if (env->pipe_in != -1)
		{
			dup2(bk_stdin, STDIN_FILENO);
			close(bk_stdin);
		}
		if (env->pipe_out != -1)
		{
			dup2(bk_stdout, STDOUT_FILENO);
			close(bk_stdout);
		}
	}
	return (1);
}

static t_env	*select_fd(t_env *env)
{
	if (env->fd_in != -1 && env->fd_in != 0)
	{
		if (env->pipe_in != -1)
			close(env->pipe_in);
	}
	else
	{
		if (env->pipe_in != -1)
			env->fd_in = env->pipe_in;
	}
	if (env->fd_out != -1 && env->fd_out != 1)
	{
		if (env->pipe_out != -1)
			close(env->pipe_out);
	}
	else
	{
		if(env->pipe_out != -1)
			env->fd_out = env->pipe_out;
	}
	return (env);
}

static void	run_cmd(t_env *env, t_grpvar *grpvar)
{
	t_dynarrstr *varenv;

	varenv = lstvar_to_array(grpvar->global);
	if (varenv->size > 0)
		execve(env->path, env->args, varenv->array);
	else
		execve(env->path, env->args, NULL);
	free(varenv);
}

static void	run_builtins(t_env *env, t_ctx *ctx)
{
	lstbuiltins_exec(ctx->lstbltins, env->path, env->args, ctx);
}

static pid_t *make_pids(pid_t *pids, int num_pids)
{
	int	i;

	i = 0;
	if (!pids)
	{
		pids = malloc(sizeof(pid_t *) * num_pids);
		if (!pids)
		{
			ft_puterror("Malloc failed");
			return (NULL);
		}
		while (i < num_pids)
		{
			pids[i] = -1;
			++i;
		}
	}
	return (pids);
}

static void	wait_all(pid_t *pids, int num_cmd)
{
	int	i;

	i = 0;
	while (i < num_cmd)
	{
		waitpid(pids[i], NULL, 0);
		++i;
	}
}

static void	close_unused_pipes(int **pipes_list, int nbr_pipes, int pipe_in, int pipe_out)
{
	int	i;

	i = 0;
	while (i < nbr_pipes)
	{
		if (pipes_list[i][0] != pipe_in && pipes_list[i][0] != pipe_out && pipes_list[i][0] != -1)
			close(pipes_list[i][0]);
		if (pipes_list[i][1] != pipe_in && pipes_list[i][1] != pipe_out && pipes_list[i][1] != -1)
			close(pipes_list[i][1]);
		++i;
	}
}
