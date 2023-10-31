/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:19:55 by lray              #+#    #+#             */
/*   Updated: 2023/10/30 13:56:52 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
