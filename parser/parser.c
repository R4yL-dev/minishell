/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:29:53 by lray              #+#    #+#             */
/*   Updated: 2023/08/11 23:26:53 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_tree_node	*parser(t_dyntklist *tklist)
{
	t_tree_node	*tree;
	int			i;

	tree = tree_new(tklist->array[0]->type, tklist->array[0]->value);
	if (tklist->size < 1)
		return (tree);
	i = 1;
	while (tklist->array[i])
	{
		tree_add(tree, tree_new(tklist->array[i]->type, tklist->array[i]->value));
		i++;
	}
	return (tree);
}
