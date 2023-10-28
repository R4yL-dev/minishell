/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:19:55 by lray              #+#    #+#             */
/*   Updated: 2023/10/26 20:55:59 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	valide_tree(t_ctx *ctx, t_dyntree *root);
static int	is_quote(char c);
int	delete_quotes(t_dyntree *root);

int	expand(t_ctx *ctx)
{
	if (!ctx->tree || !ctx->grpvar)
		return (0);
	if (!replace_var(ctx->tree, ctx))
		return (0);
	delete_quotes(ctx->tree);
	if (!valide_tree(ctx, ctx->tree))
		return (0);
	replace_builtins(ctx->tree, ctx);
	return (1);
}

static int	valide_tree(t_ctx *ctx, t_dyntree *root)
{
	size_t	i;

	if (!root)
		return (0);
	if (root->type == TK_FILE)
	{
		if (root->value[0] == '\0')
		{
			ctx->ret_code = 2;
			ft_puterror("ambiguous redirect");
			return (0);
		}
	}
	else if (root->type == TK_PIPE)
	{
		if (root->numChildren < 2)
		{
			ctx->ret_code = 2;
			ft_puterror("ambiguous redirect");
			return (0);
		}
	}
	else if (root->type == TK_COMMAND)
	{
		if (root->value[0] == '\0')
			return (0);
	}
	else if (root->type == TK_REDIRECTION)
	{
		if (root->numChildren < 1 || root->children[0]->type != TK_FILE)
			return (0);
	}
	i = 0;
	while (i < root->numChildren)
	{
		if (!valide_tree(ctx, root->children[i++]))
			return (0);
	}
	return (1);
}

int	delete_quotes(t_dyntree *root)
{
	size_t	i_child;
	size_t	i_str;
	char	quote;

	quote = 0;
	if (root->type == TK_COMMAND || root->type == TK_ARGUMENT || root->type == TK_FILE)
	{
		i_str = 0;
		while (root->value[i_str] != '\0')
		{
			if (is_quote(root->value[i_str]))
			{
				if (quote == 0)
				{
					quote = root->value[i_str];
					ft_memmove(root->value + i_str, root->value + i_str + 1, ft_strlen(root->value + i_str));
					--i_str;
				}
				else if (root->value[i_str] == quote)
				{
					quote = 0;
					ft_memmove(root->value + i_str, root->value + i_str + 1, ft_strlen(root->value + i_str));
					--i_str;
				}

			}
			++i_str;
		}
	}
	i_child = 0;
	while (i_child < root->numChildren)
		delete_quotes(root->children[i_child++]);
	return (1);
}

static int	is_quote(char c)
{
	if (c == '\'' || c == '"')
		return (1);
	return (0);
}
