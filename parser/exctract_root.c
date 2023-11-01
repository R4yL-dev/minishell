/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exctract_root.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:56:28 by lray              #+#    #+#             */
/*   Updated: 2023/10/30 12:56:49 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_dyntree	*exctract_root(t_dyntklist *tklist)
{
	t_dyntree	*root;
	int			i;

	root = NULL;
	i = 0;
	if (has_token_type(tklist, TK_PIPE) != -1)
	{
		while (tklist->array[i]->type != TK_PIPE)
			i++;
		root = dyntree_new(TK_PIPE, "|");
	}
	else if (has_token_type(tklist, TK_COMMAND) != -1)
	{
		while (tklist->array[i]->type != TK_COMMAND)
			i++;
		root = dyntree_new(tklist->array[i]->type, tklist->array[i]->value);
	}
	else if (has_token_type(tklist, TK_REDIRECTION) != -1)
	{
		while (tklist->array[i]->type != TK_REDIRECTION)
			i++;
		root = dyntree_new(tklist->array[i]->type, tklist->array[i]->value);
	}
	return (root);
}
