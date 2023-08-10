/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tklist.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 00:15:28 by lray              #+#    #+#             */
/*   Updated: 2023/08/10 01:26:08 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TKLIST_H
# define TKLIST_H

typedef struct s_tklist
{
	int					type;
	char				*value;
	struct s_tklist		*next;
}						t_tklist;

t_tklist	*tklist_new(char *value, int type);
void		tklist_add(t_tklist **lst, t_tklist *new);
t_tklist	*tklist_last(t_tklist *lst);

#endif
