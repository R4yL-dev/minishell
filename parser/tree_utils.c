/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 22:28:18 by lray              #+#    #+#             */
/*   Updated: 2023/08/10 22:31:55 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	tree_count_node(t_tree_node *tree)
{
	int	nbr_node;
	int	i;

	nbr_node = 0;
	i = 0;
	if (tree != NULL)
	{
		nbr_node++;
		while (tree->children[i])
		{
			nbr_node++;
			i++;
		}
	}
	return (nbr_node);
}
