/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstvar.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:10:55 by lray              #+#    #+#             */
/*   Updated: 2023/09/26 17:40:42 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LSTVAR_H
# define LSTVAR_H

# define LSTVAR_INITIAL_CAP 2

typedef struct s_lstvar
{
	t_var	**array;
	size_t	capacity;
	size_t	num_elements;
}	t_lstvar;

t_lstvar	*lstvar_init(void);
int			lstvar_add(t_lstvar *lstvar, t_var *var);
void		lstvar_show(t_lstvar *lstvar);
size_t		lstvar_has(t_lstvar *lstvar, char *name);
void		lstvar_free(t_lstvar *lstvar);

#endif
