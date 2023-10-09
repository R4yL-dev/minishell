/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstbuiltins_exec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:20:00 by lray              #+#    #+#             */
/*   Updated: 2023/10/09 20:24:45 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	lstbuiltins_exec(t_lstbuiltins *head, char *name, char **argv, t_ctx *ctx)
{
	t_lstbuiltins	*p_lst;

	if (!head || !name)
		return (-1);
	p_lst = head;
	while (p_lst)
	{
		if (ft_strncmp(p_lst->name, name, ft_strlen(p_lst->name)) == 0 &&\
		ft_strlen(p_lst->name) == ft_strlen(name))
			return (p_lst->func(argv, ctx));
		p_lst = p_lst->next;
	}
	return (-1);
}
