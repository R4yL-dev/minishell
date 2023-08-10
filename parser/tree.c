/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:50:40 by lray              #+#    #+#             */
/*   Updated: 2023/08/10 15:30:44 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
	TODO:
		- Gerer les erreur de malloc
		- Il faut peut être ajouter l'init de new->children
*/
t_tree_node *tree_new(int type, char *value)
{
	t_tree_node	*new;
	int			i;
	int			j;

	new = malloc(sizeof(t_tree_node));
	if (new == NULL)
		return NULL;
	new->type = type;
	new->value = value;
	i = 0;
	j = 0;
	while (i < MAX_CHILDREN)
	{
		new->children[i] = malloc(sizeof(t_tree_node));
		if (new->children[i] == NULL)
		{
			// If we run out of memory, free all previously allocated nodes and return NULL
			j = 0;
			while (j < i)
			{
				free(new->children[j]);
				j++;
			}
			free(new);
			return NULL;
		}
		new->children[i] = NULL;
		i++;
	}
	return new;
}


void	tree_add(t_tree_node *parent, t_tree_node *child)
{
	int	i;

	i = 0;
	while (i < MAX_CHILDREN)
	{
		if (parent->children[i] == NULL)
		{
			parent->children[i] = child;
			return ;
		}
		i++;
	}
	printf("ERROR\n");
}

/*
	TODO:
		- Nous avons besoin d'une fonction qui free l'arbre
*/
