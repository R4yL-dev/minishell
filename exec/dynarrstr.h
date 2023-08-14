/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynarrstr.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:27:12 by lray              #+#    #+#             */
/*   Updated: 2023/08/14 02:07:07 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DYNARRSTR_H
# define DYNARRSTR_H

typedef struct s_dynarrstr
{
	char	**array;
	size_t	size;
}	t_dynarrstr;

t_dynarrstr	*dynarrstr_init(t_dynarrstr *dynarr);
int			dynarrstr_add(t_dynarrstr *dynarr, char *value);
void		dynarrstr_show(t_dynarrstr *dynarr);
void		dynarrstr_free(t_dynarrstr *dynarr);

#endif
