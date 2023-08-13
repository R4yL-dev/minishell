/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:29:53 by lray              #+#    #+#             */
/*   Updated: 2023/08/13 19:52:42 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_dyntree	*parser(t_dyntklist *tklist)
{
	t_dyntree	*tree;
	int			i;

	tree = dyntree_new(tklist->array[0]->type, tklist->array[0]->value);
	if (tklist->size < 1)
		return (tree);
	i = 1;
	while (tklist->array[i])
	{
		dyntree_add(tree, dyntree_new(tklist->array[i]->type, tklist->array[i]->value));
		i++;
	}
	return (tree);
}
