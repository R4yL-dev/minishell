/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstvar.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:10:55 by lray              #+#    #+#             */
/*   Updated: 2023/10/07 14:52:30 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LSTVAR_H
# define LSTVAR_H

# define LSTVAR_INITIAL_CAP 2

# include "../exec/dynarrstr.h"

typedef struct s_lstvar
{
	t_var	**array;
	size_t	capacity;
	size_t	num_elements;
}	t_lstvar;

t_lstvar	*lstvar_init(char **envp);
int			lstvar_add(t_lstvar *lstvar, t_var *var);
void		lstvar_show(t_lstvar *lstvar);
size_t		lstvar_has(t_lstvar *lstvar, char *name);
int			lstvar_remove(t_lstvar *lstvar, size_t index);
void		lstvar_free(t_lstvar *lstvar);
t_dynarrstr	*lstvar_to_array(t_lstvar *lstvar);


#endif
