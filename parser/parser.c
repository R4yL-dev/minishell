/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:29:53 by lray              #+#    #+#             */
/*   Updated: 2023/10/30 13:46:11 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	parser(t_ctx *ctx)
{
	size_t		i;
	int			last_pipe;

	ctx->tree = exctract_root(ctx->tklist);
	if (ctx->tree->type == TK_COMMAND || ctx->tree->type == TK_REDIRECTION)
		add_to_cmd(ctx->tklist, ctx->tree, 0);
	else if (ctx->tree->type == TK_PIPE)
	{
		add_cmd_to_root(ctx->tklist, ctx->tree);
		i = 0;
		last_pipe = 0;
		while (i < ctx->tree->num_children)
		{
			last_pipe = add_to_cmd(ctx->tklist, \
			ctx->tree->children[i], last_pipe) + 1;
			++i;
		}
	}
	else
	{
		ft_puterror("Unknow root");
		return (0);
	}
	return (1);
}
