/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstbuiltins_has.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:05:37 by lray              #+#    #+#             */
/*   Updated: 2023/10/09 20:25:21 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_lstbuiltins	*lstbuiltins_has(t_lstbuiltins *head, char *name)
{
	t_lstbuiltins	*p_lst;

	if (!head || !name)
		return (NULL);
	p_lst = head;
	while (p_lst)
	{
		if (ft_strncmp(p_lst->name, name, ft_strlen(p_lst->name)) == 0 &&\
		ft_strlen(p_lst->name) == ft_strlen(name))
			return (p_lst);
		p_lst = p_lst->next;
	}
	return (NULL);
}
