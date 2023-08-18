/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dyntklist.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 21:36:45 by lray              #+#    #+#             */
/*   Updated: 2023/08/18 13:24:32 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DYNTKLIST_H
# define DYNTKLIST_H

typedef struct s_dyntklist
{
	t_token	**array;
	size_t	size;
}	t_dyntklist;

t_dyntklist	*dyntklist_init(t_dyntklist *tklist);
int			dyntklist_add(t_dyntklist *tklist, int type, char *value);
void		dyntklist_show(t_dyntklist *tklist);
int			dyntklist_delone(t_dyntklist *tklist, int id);
void		dyntklist_free(t_dyntklist *tklist);

#endif
