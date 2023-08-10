/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tklist.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 00:14:39 by lray              #+#    #+#             */
/*   Updated: 2023/08/10 01:36:06 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_tklist	*tklist_new(char *value, int type)
{
	t_tklist	*new;

	new = malloc(sizeof(t_tklist));
	if (new == NULL)
		return (NULL);
	new->value = ft_strdup(value);
	new->type = type;
	new->next = NULL;
	return (new);
}

void	tklist_add(t_tklist **lst, t_tklist *new)
{
	t_tklist	*last;

	last = tklist_last(*lst);
	if (!last)
		*lst = new;
	else
		last->next = new;

}

t_tklist	*tklist_last(t_tklist *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

