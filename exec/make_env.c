/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:22:36 by lray              #+#    #+#             */
/*   Updated: 2023/11/02 13:12:41 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static t_env	*set_env_cmd(t_ctx *c, t_dyntree *r, int in_out[2]);
static t_env	*set_env_blt(t_ctx *c, t_dyntree *r, int in_out[2]);
static t_env	*set_env_red(t_ctx *c, t_dyntree *r, int in_out[2]);

t_env	*make_env(t_ctx *ctx, t_dyntree *root, int in_out[2])
{
	ctx->env = env_new();
	if (root->type == TK_COMMAND)
		ctx->env = set_env_cmd(ctx, root, in_out);
	else if (root->type == TK_BUILTINS)
		ctx->env = set_env_blt(ctx, root, in_out);
	else if (root->type == TK_REDIRECTION)
		ctx->env = set_env_red(ctx, root, in_out);
	if (ctx->env == NULL)
		return (NULL);
	return (ctx->env);
}

static t_env	*set_env_cmd(t_ctx *c, t_dyntree *r, int in_out[2])
{
	t_dynarrstr	*argv;

	argv = NULL;
	c->env->type = TK_COMMAND;
	c->env->path = get_cmd_path(r->value, c->grpvar);
	if (!c->env->path)
	{
		ft_puterror("command not found");
		g_code = 127;
		c->env = env_free(c->env);
		return (NULL);
	}
	argv = make_argv(r);
	c->env->args = arrcpy(argv->array, (int)argv->size);
	dynarrstr_free(argv);
	c->env->fd_in = get_infd(r, c);
	if (c->env->fd_in == -1)
	{
		c->env = env_free(c->env);
		return (NULL);
	}
	c->env->fd_out = get_outfd(r);
	c->env->pipe_in = in_out[0];
	c->env->pipe_out = in_out[1];
	return (c->env);
}

static t_env	*set_env_blt(t_ctx *c, t_dyntree *r, int in_out[2])
{
	t_dynarrstr	*argv;

	argv = NULL;
	c->env->type = TK_BUILTINS;
	c->env->path = ft_strdup(r->value);
	argv = make_argv(r);
	if (!argv)
	{
		c->env = env_free(c->env);
		return (NULL);
	}
	c->env->args = arrcpy(argv->array, (int)argv->size);
	dynarrstr_free(argv);
	c->env->fd_in = get_infd(r, c);
	c->env->fd_out = get_outfd(r);
	c->env->pipe_in = in_out[0];
	c->env->pipe_out = in_out[1];
	return (c->env);
}

static t_env	*set_env_red(t_ctx *c, t_dyntree *r, int in_out[2])
{
	c->env->type = TK_REDIRECTION;
	c->env->path = NULL;
	c->env->args = NULL;
	c->env->fd_in = get_infd(r, c);
	c->env->fd_out = get_outfd(r);
	c->env->pipe_in = in_out[0];
	c->env->pipe_out = in_out[1];
	return (c->env);
}
