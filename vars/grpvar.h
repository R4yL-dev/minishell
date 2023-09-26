/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grpvar.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 19:02:08 by lray              #+#    #+#             */
/*   Updated: 2023/09/26 20:32:34 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRPVAR_H
# define GRPVAR_H

typedef struct s_grpvar
{
	t_lstvar	*global;
	t_lstvar	*local;
}	t_grpvar;

# define GRPVAR_GLOBAL 0
# define GRPVAR_LOCAL 1

t_grpvar	*grpvar_init(char **envp);
int			grpvar_add(t_grpvar *grpvar, int lstvar, char *name, char *value);
void		grpvar_show(t_grpvar *grpvar);
size_t		grpvar_has(t_grpvar *grpvar, int lstvar, char *name);
int			grpvar_remove(t_grpvar *grpvar, int lstvar, size_t index);
void		grpvar_free(t_grpvar *grpvar);

#endif
