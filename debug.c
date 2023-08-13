/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:31:46 by lray              #+#    #+#             */
/*   Updated: 2023/08/13 19:28:30 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	db_show_tree(t_dyntree *root, int depth)
{
	size_t	i;

	i = 0;
	while (i < (size_t)depth)
	{
		printf("  ");
		i++;
	}
	printf("node->type : ");
	if (root->type == 0)
		printf("TK_COMMAND");
	else if (root->type == 1)
		printf("TK_ARGUMENT");
	else if (root->type == 2)
		printf("TK_FILE");
	else if (root->type == 3)
		printf("TK_REDIRECTION");
	else if (root->type == 4)
		printf("TK_PIPE");
	else
		printf("Unknow token");
	printf(" | node->value : \"%s\" | %ld/%ld\n", root->value, root->numChildren, root->capacity);

	i = 0;
	while (i < root->numChildren)
		db_show_tree(root->children[i++], depth + 1);
}
