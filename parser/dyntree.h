/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dyntree.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 18:11:07 by lray              #+#    #+#             */
/*   Updated: 2023/10/11 13:46:11 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DYNTREE_H
# define DYNTREE_H

# define DYNTREE_INITIAL_CAP 2

typedef struct s_dyntree
{
	int					type;
	char				*value;
	struct s_dyntree	**children;
	size_t				numChildren;
	size_t				capacity;
}	t_dyntree;

t_dyntree	*dyntree_new(int type, char *value);
int			dyntree_add(t_dyntree *parent, t_dyntree *child);
void		dyntree_show(t_dyntree *root, int depth);
void		dyntree_free(t_dyntree *node);

#endif
