/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:39:00 by lray              #+#    #+#             */
/*   Updated: 2023/10/31 21:06:49 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VAR_H
# define VAR_H

typedef struct s_var
{
	char	*name;
	char	*value;
}	t_var;

t_var	*var_new(char *name, char *value);

void	var_show(t_var *var);

void	var_free(t_var *var);

#endif
