/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:29:53 by lray              #+#    #+#             */
/*   Updated: 2023/08/14 01:36:02 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_dyntree	*parser(t_dyntklist *tklist)
{
	t_dyntree	*tree;
	int			i;

	tree = dyntree_new(tklist->array[0]->type, tklist->array[0]->value);
	if (tree == NULL)
		return (NULL);
	if (tklist->size < 1)
		return (tree);
	i = 1;
	while (tklist->array[i])
	{
		if (dyntree_add(tree, dyntree_new(tklist->array[i]->type, tklist->array[i]->value)) == 0)
			return (NULL);
		i++;
	}
	return (tree);
}
