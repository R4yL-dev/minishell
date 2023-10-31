/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstbuiltins_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:33:13 by lray              #+#    #+#             */
/*   Updated: 2023/10/31 20:33:32 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	lstbuiltins_free(t_lstbuiltins *node)
{
	if (node)
	{
		if (node->name)
		{
			free(node->name);
			node->name = NULL;
		}
		node->func = NULL;
		node->next = NULL;
		free(node);
		node = NULL;
	}
}

void	lstbuiltins_freeall(t_lstbuiltins *head)
{
	t_lstbuiltins	*next;

	if (!head)
		return ;
	while (head)
	{
		next = head->next;
		lstbuiltins_free(head);
		head = next;
	}
}
