/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dyntree.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 18:09:29 by lray              #+#    #+#             */
/*   Updated: 2023/10/30 13:45:52 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_dyntree	*dyntree_new(int type, char *value)
{
	t_dyntree	*node;

	node = (t_dyntree *)malloc(sizeof(t_dyntree));
	if (node != NULL)
	{
		node->type = type;
		node->value = ft_strdup(value);
		if (node->value == NULL)
		{
			ft_puterror("Ft_strdup failed");
			return (NULL);
		}
		node->num_children = 0;
		node->capacity = DYNTREE_INITIAL_CAP;
		node->children = (t_dyntree **)malloc(node->capacity \
		* sizeof(t_dyntree *));
		if (node->children == NULL)
		{
			ft_puterror("Malloc failed");
			return (NULL);
		}
	}
	return (node);
}

int	dyntree_add(t_dyntree *parent, t_dyntree *child)
{
	if (parent->num_children == parent->capacity)
	{
		parent->capacity *= 2;
		parent->children = (t_dyntree **)ft_realloc(parent->children, \
		(parent->capacity / 2) * sizeof(t_dyntree *), \
		parent->capacity * sizeof(t_dyntree *));
		if (parent->children == NULL)
		{
			ft_puterror("Realloc failed");
			return (0);
		}
	}
	parent->children[parent->num_children++] = child;
	return (1);
}

void	dyntree_show(t_dyntree *root, int depth)
{
	size_t	i;

	i = 0;
	while (i < (size_t)depth)
	{
		printf("  ");
		i++;
	}
	printf("node->type %d | node->value : \"%s\"\n", root->type, root->value);
	i = 0;
	while (i < root->num_children)
		dyntree_show(root->children[i++], depth + 1);
}

void	dyntree_free(t_dyntree *node)
{
	size_t	i;

	if (node == NULL)
		return ;
	i = 0;
	while (i < node->num_children)
		dyntree_free(node->children[i++]);
	free(node->children);
	node->children = NULL;
	free(node->value);
	node->value = NULL;
	free(node);
	node = NULL;
}
