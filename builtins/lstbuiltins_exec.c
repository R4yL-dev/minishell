/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstbuiltins_exec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:20:00 by lray              #+#    #+#             */
/*   Updated: 2023/10/31 20:38:08 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	lstbuiltins_exec(t_lstbuiltins *h, char *n, char **a, t_ctx *c)
{
	t_lstbuiltins	*p_lst;

	if (!h || !n)
		return (-1);
	p_lst = h;
	while (p_lst)
	{
		if (ft_strncmp(p_lst->name, n, ft_strlen(p_lst->name)) == 0 && \
		ft_strlen(p_lst->name) == ft_strlen(n))
			return (p_lst->func(a, c));
		p_lst = p_lst->next;
	}
	return (-1);
}
