/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 22:19:41 by lray              #+#    #+#             */
/*   Updated: 2023/10/09 14:21:00 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	t_env_node	*make_env_list(t_dyntree *root, t_grpvar *grpvar, t_env_node *envlist);
static	t_env_node	*make_env_node(t_dyntree *root, t_grpvar *grpvar, t_env_node *envlist, int pipe_in, int pipe_out);
static int	exec_env_list(t_grpvar *grpvar,t_env_node *head);
static void	run_cmd(t_grpvar *grpvar, t_env_node *p_env, int fd_in, int fd_out);

int	exec(t_ctx *ctx)
{
	t_env_node	*envlist;

	envlist = NULL;
	envlist = make_env_list(ctx->tree, ctx->grpvar, envlist);
	exec_env_list(ctx->grpvar, envlist);
	env_node_freeall(envlist);
	return (1);
}

static	t_env_node	*make_env_list(t_dyntree *root, t_grpvar *grpvar, t_env_node *envlist)
{
	int		**pipes_list;
	size_t	i_child;

	pipes_list = NULL;
	if (root->type == TK_PIPE)
	{
		pipes_list = pipes_list_create((int)root->numChildren - 1);
		i_child = 0;
		while (i_child < root->numChildren)
		{
			if (i_child == 0)
				envlist = make_env_node(root->children[i_child], grpvar, envlist, -1, pipes_list[i_child][1]);
			else if ((int)i_child == (int)root->numChildren - 1)
				envlist = make_env_node(root->children[i_child], grpvar, envlist, pipes_list[(int)i_child - 1][0], -1);
			else
				envlist = make_env_node(root->children[i_child], grpvar, envlist, pipes_list[(int)i_child - 1][0], pipes_list[i_child][1]);
			if (envlist == NULL)
			{
				env_node_freeall(envlist);
				return (0);
			}
			i_child++;
		}
		pipes_list_free(pipes_list, (int)root->numChildren - 1);
	}
	else
	{
		envlist = make_env_node(root, grpvar, envlist, -1, -1);
		if (envlist == NULL)
		{
			env_node_freeall(envlist);
			return (0);
		}

	}
	return (envlist);
}

static	t_env_node	*make_env_node(t_dyntree *root, t_grpvar *grpvar, t_env_node *envlist, int pipe_in, int pipe_out)
{
	t_env_node	*last_el;
	t_dynarrstr	*argv;

	if (envlist == NULL)
		envlist = env_node_new();
	else
		envlist = env_node_add(envlist, NULL);
	last_el = env_node_getlast(envlist);
	if (root->type == TK_COMMAND)
	{
		last_el->path = get_cmd_path(root->value, grpvar);
		if (!last_el->path)
		{
			ft_puterror("command not found");
			return (NULL);
		}
		argv = make_argv(root);
		if (argv == NULL)
			return (NULL);
		last_el->args = arrcpy(argv->array, (int)argv->size);
		dynarrstr_free(argv);
		last_el->fd_in = get_infd(root);
		last_el->fd_out = get_outfd(root);
		last_el->pipe_in = pipe_in;
		last_el->pipe_out = pipe_out;
	}
	else if (root->type == TK_REDIRECTION)
	{
		last_el->path = NULL;
		last_el->path = NULL;
		last_el->fd_in = get_infd(root);
		last_el->fd_out = get_outfd(root);
		last_el->pipe_in = pipe_in;
		last_el->pipe_out = pipe_out;
	}
	return (envlist);
}

static int	exec_env_list(t_grpvar *grpvar,t_env_node *head)
{
	t_env_node	*p_env;
	pid_t		pid;
	int			status;
	int			fd_in;
	int			fd_out;

	if (head == NULL)
		return (0);
	p_env = head;
	while (p_env)
	{
		if (p_env->path == NULL)
		{
			p_env = p_env->next;
			continue ;
		}
		fd_in = 0;
		fd_out = 1;
		if (p_env->fd_in != 0)
		{
			fd_in = p_env->fd_in;
			if (p_env->pipe_in != -1)
				close(p_env->pipe_in);
		}
		else if (p_env->fd_in == 0 && p_env->pipe_in != -1)
			fd_in = p_env->pipe_in;
		if (p_env->fd_out != 1)
		{
			fd_out = p_env->fd_out;
			if (p_env->pipe_out != -1)
				close(p_env->pipe_out);
		}
		else if (p_env->fd_out == 1 && p_env->pipe_out != -1)
			fd_out = p_env->pipe_out;
		pid = fork();
		if (pid == 0)
			run_cmd(grpvar, p_env, fd_in, fd_out);
		else
		{
			waitpid(pid, &status, 0);
			if (fd_in != 0)
				close(fd_in);
			if (fd_out != 1)
				close(fd_out);
		}
		p_env = p_env->next;
	}
	return (1);
}

static void	run_cmd(t_grpvar *grpvar, t_env_node *p_env, int fd_in, int fd_out)
{
	t_dynarrstr *varenv;

	dup2(fd_in, STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	varenv = lstvar_to_array(grpvar->global);
	if (varenv->size > 0)
		execve(p_env->path, p_env->args, varenv->array);
	else
		execve(p_env->path, p_env->args, NULL);
}
