/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_builtins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:17:17 by lray              #+#    #+#             */
/*   Updated: 2023/10/09 20:52:15 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	replace_builtins(t_dyntree *root, t_ctx *ctx)
{
	size_t	i_child;

	if (root->type == TK_COMMAND)
	{
		if (lstbuiltins_has(ctx->lstbltins, root->value))
		{
			root->type = TK_BUILTINS;
		}
	}
	i_child = 0;
	while (i_child < root->numChildren)
	{
		if (!replace_builtins(root->children[i_child++], ctx))
			return (0);
	}
	return (1);
}
