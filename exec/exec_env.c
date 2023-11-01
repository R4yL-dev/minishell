/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:26:02 by lray              #+#    #+#             */
/*   Updated: 2023/11/01 16:20:38 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int		select_fd(t_env *env);
static void		run_cmd(t_env *env, t_grpvar *grpvar);
static void		run_builtins(t_ctx *ctx);
static void		close_unused(int **pl, int nbr_p, int p_in, int p_out);

int	exec_env(t_ctx *ctx, pid_t *pid, int **pl, int nbr_p)
{
	select_fd(ctx->env);
	if (ctx->env->type == TK_COMMAND)
	{
		*pid = fork();
		if (*pid == 0)
		{
			dup2(ctx->env->fd_in, STDIN_FILENO);
			dup2(ctx->env->fd_out, STDOUT_FILENO);
			if (pl)
				close_unused(pl, nbr_p, ctx->env->pipe_in, ctx->env->pipe_out);
			run_cmd(ctx->env, ctx->grpvar);
		}
		else if (*pid > 0)
		{
			if (ctx->env->fd_in != 0)
				close(ctx->env->fd_in);
			if (ctx->env->fd_out != 1)
				close(ctx->env->fd_out);
		}
	}
	else if (ctx->env->type == TK_BUILTINS)
		run_builtins(ctx);
	return (1);
}

static int	select_fd(t_env *env)
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
		if (env->pipe_out != -1)
			env->fd_out = env->pipe_out;
	}
	return (1);
}

static void	run_cmd(t_env *env, t_grpvar *grpvar)
{
	t_dynarrstr	*varenv;

	varenv = lstvar_to_array(grpvar->global);
	if (varenv->size > 0)
		execve(env->path, env->args, varenv->array);
	else
		execve(env->path, env->args, NULL);
	free(varenv);
}

static void	run_builtins(t_ctx *ctx)
{
	int	bk_stdin;
	int	bk_stdout;

	if (ctx->env->fd_in != 0)
	{
		bk_stdin = dup(STDIN_FILENO);
		dup2(ctx->env->fd_in, STDIN_FILENO);
	}
	if (ctx->env->fd_out != 1)
	{
		bk_stdout = dup(STDOUT_FILENO);
		dup2(ctx->env->fd_out, STDOUT_FILENO);
	}
	ctx->ret_code =  lstbuiltins_exec(ctx->lstbltins, ctx->env->path, ctx->env->args, ctx);
	if (ctx->env->fd_in != 0)
	{
		dup2(bk_stdin, STDIN_FILENO);
		close(bk_stdin);
	}
	if (ctx->env->fd_out != 1)
	{
		dup2(bk_stdout, STDOUT_FILENO);
		close(bk_stdout);
	}
}

static void	close_unused(int **pl, int nbr_p, int p_in, int p_out)
{
	int	i;

	i = 0;
	while (i < nbr_p)
	{
		if (pl[i][0] != p_in && pl[i][0] != p_out && pl[i][0] != -1)
			close(pl[i][0]);
		if (pl[i][1] != p_in && pl[i][1] != p_out && pl[i][1] != -1)
			close(pl[i][1]);
		++i;
	}
}
