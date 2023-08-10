/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:31:46 by lray              #+#    #+#             */
/*   Updated: 2023/08/10 15:30:41 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	db_show_tklist(t_tklist *tklist)
{
	t_tklist	*tmp;

	tmp = tklist;
	while (tmp)
	{
		printf("value: %s\n", tmp->value);
		printf("type: %d\n", tmp->type);
		tmp = tmp->next;
	}
}

void	db_show_tree(t_tree_node *node, int depth)
{
	int	i;

	i = 0;
	while (i < depth)
	{
		printf("  ");
		i++;
	}
	printf("%s\n", node->value);

	i = 0;
	while (i < MAX_CHILDREN && node->children[i] != NULL)
	{
		db_show_tree(node->children[i], depth + 1);
		i++;
	}
}
