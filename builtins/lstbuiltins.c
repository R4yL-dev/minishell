/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstbuiltins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:32:21 by lray              #+#    #+#             */

/*   Updated: 2023/10/10 21:17:43 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_lstbuiltins	*lstbuiltins_new(char *name, int (*func)(char **argv, t_ctx *ctx))
{
	t_lstbuiltins	*lst;

	if (!name || !func)
		return (NULL);
	lst = malloc(sizeof(t_lstbuiltins));
	if (!lst)
	{
		ft_puterror("Malloc failed");
		return (NULL);
	}
	lst->name = ft_strdup(name);
	lst->func = func;
	lst->next = NULL;
	return (lst);
}

t_lstbuiltins *lstbuiltins_init(t_lstbuiltins *head)
{
	head = lstbuiltins_new("showctx", builtin_showctx);
	lstbuiltins_add(head, lstbuiltins_new("echo", builtin_echo));
	lstbuiltins_add(head, lstbuiltins_new("pwd", builtin_pwd));
	lstbuiltins_add(head, lstbuiltins_new("exit", builtin_exit));
	lstbuiltins_add(head, lstbuiltins_new("export", builtin_export));
	lstbuiltins_add(head, lstbuiltins_new("clear", builtin_clear));
	return (head);
}

t_lstbuiltins	*lstbuiltins_getlast(t_lstbuiltins *head)
{
	t_lstbuiltins	*p_lst;
	if (!head)
		return (NULL);
	p_lst = head;
	while (p_lst->next != NULL)
		p_lst = p_lst->next;
	return (p_lst);
}

int	lstbuiltins_add(t_lstbuiltins *head, t_lstbuiltins *new)
{
	t_lstbuiltins	*last_el;

	if (!head || !new)
		return (0);
	last_el = lstbuiltins_getlast(head);
	last_el->next = new;
	return (1);
}

void	lstbuiltins_show(t_lstbuiltins *head)
{
	t_lstbuiltins	*p_lst;

	if (!head)
		return ;
	p_lst = head;
	printf("= LSTBUILTINS SHOW =\n");
	while (p_lst)
	{
		printf("-> Builtins %s\n", p_lst->name);
		printf("\tFunction address : %p\n", p_lst->func);
		printf("\tNext builtin address: %p\n", p_lst->next);
		p_lst = p_lst->next;
	}
}

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
