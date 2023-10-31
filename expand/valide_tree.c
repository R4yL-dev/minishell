/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valide_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:53:36 by lray              #+#    #+#             */
/*   Updated: 2023/10/30 18:05:56 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	process_file(t_ctx *ctx, t_dyntree *root);
static int	process_pipe(t_ctx *ctx, t_dyntree *root);
static int	process_cmd(t_dyntree *root);
static int	process_redirect(t_dyntree *root);

int	valide_tree(t_ctx *ctx, t_dyntree *root)
{
	size_t	i;

	if (!root)
		return (0);
	if (process_file(ctx, root) == 0)
		return (0);
	if (process_pipe(ctx, root) == 0)
		return (0);
	if (process_cmd(root) == 0)
		return (0);
	if (process_redirect(root) == 0)
		return (0);
	i = 0;
	while (i < root->num_children)
	{
		if (!valide_tree(ctx, root->children[i++]))
			return (0);
	}
	return (1);
}

static int	process_file(t_ctx *ctx, t_dyntree *root)
{
	if (root->type == TK_FILE)
	{
		if (root->value[0] == '\0')
		{
			ctx->ret_code = 2;
			ft_puterror("ambiguous redirect");
			return (0);
		}
	}
	return (1);
}

static int	process_pipe(t_ctx *ctx, t_dyntree *root)
{
	if (root->type == TK_PIPE)
	{
		if (root->num_children < 2)
		{
			ctx->ret_code = 2;
			ft_puterror("ambiguous redirect");
			return (0);
		}
	}
	return (1);
}

static int	process_cmd(t_dyntree *root)
{
	if (root->type == TK_COMMAND)
	{
		if (root->value[0] == '\0')
			return (0);
	}
	return (1);
}

static int	process_redirect(t_dyntree *root)
{
	if (root->type == TK_REDIRECTION)
	{
		if (root->num_children < 1 || root->children[0]->type != TK_FILE)
			return (0);
	}
	return (1);
}
