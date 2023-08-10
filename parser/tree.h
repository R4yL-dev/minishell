/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:50:53 by lray              #+#    #+#             */
/*   Updated: 2023/08/10 15:30:41 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_H
# define TREE_H

# define MAX_CHILDREN 100

typedef struct s_tree_node
{
	int					type;
	char				*value;
	struct s_tree_node	*children[MAX_CHILDREN];
}	t_tree_node;

t_tree_node	*tree_new(int type, char *value);
void	tree_add(t_tree_node *parent, t_tree_node *child);


#endif
