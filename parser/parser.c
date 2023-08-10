/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:29:53 by lray              #+#    #+#             */
/*   Updated: 2023/08/10 14:40:05 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_tree_node	*parser(t_tklist *tklist)
{
	t_tklist	*head;
	t_tree_node	*tree;

	head = tklist;
	tree = tree_new(head->type, head->value);
	if (head->next)
		head = head->next;
	else
		return (tree);
	while (head)
	{
		tree_add(tree, tree_new(head->type, head->value));
		head = head->next;
	}
	db_show_tree(tree, 0);
	return (tree);
}
