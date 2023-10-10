/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:49:07 by lray              #+#    #+#             */
/*   Updated: 2023/10/09 21:03:37 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env_node	*env_node_new(void)
{
	t_env_node *new_node;

	new_node = malloc(sizeof(t_env_node) * 1);
	if (new_node == NULL)
	{
		ft_puterror("Malloc failed");
		return (NULL);
	}
	new_node->type = -1;
	new_node->path = NULL;
	new_node->args = NULL;
	new_node->fd_in = STDIN_FILENO;
	new_node->fd_out = STDOUT_FILENO;
	new_node->pipe_in = -1;
	new_node->pipe_out = -1;
	new_node->next = NULL;
	return (new_node);
}

t_env_node	*env_node_add(t_env_node *head, t_env_node *new)
{
	t_env_node	*ptr;

	if (head == NULL)
		head = env_node_new();
	if (new == NULL)
		new = env_node_new();
	ptr = head;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = new;
	return (head);
}

t_env_node	*env_node_getlast(t_env_node *head)
{
	t_env_node	*ptr;

	if (head == NULL)
		return (NULL);
	ptr = head;
	while (ptr->next != NULL)
		ptr = ptr->next;
	return (ptr);
}

int	env_node_count(t_env_node *head)
{
	int			count;
	t_env_node	*elem;

	if (head == NULL)
		return (-1);
	elem = head;
	count = 0;
	while (elem != NULL)
	{
		count++;
		elem = elem->next;
	}
	return (count);
}

void	env_node_show(t_env_node *head)
{
	t_env_node	*node;
	int			i;

	node = head;
	while (node != NULL)
	{
		printf("type : %d\n", node->type);
		printf("path : ");
		if (node->path)
			printf("%s\n", node->path);
		else
			printf("(null)\n");

		printf("Argument :\n");
		if (node->args)
		{
			i = 0;
			while (node->args[i])
				printf("\t%s\n", node->args[i++]);
		}
		else
			printf("(null)\n");
		printf("fd_in : %d\n", node->fd_in);
		printf("fd_out : %d\n", node->fd_out);
		printf("pipe_in : %d\n", node->pipe_in);
		printf("pipe_out : %d\n", node->pipe_out);
		printf("next : %p\n\n", node->next);
		node = node->next;
	}
}

void	env_node_free(t_env_node *node)
{
	if (node != NULL)
	{
		if (node->path != NULL)
		{
			free(node->path);
			node->path = NULL;
		}
		if (node->args != NULL)
		{
			free_split(node->args);
			node->args = NULL;
		}
		if (node->fd_in > 2)
			close(node->fd_in);
		if (node->fd_out > 2)
			close(node->fd_out);
		if (node->pipe_in > 2)
			close(node->pipe_in);
		if (node->pipe_out > 2)
			close(node->pipe_out);
		free(node);
		node = NULL;
	}
}

void	env_node_freeall(t_env_node *head)
{
	t_env_node	*p_env;
	t_env_node	*p_next;

	p_env = head;
	while (p_env != NULL)
	{
		p_next = p_env->next;
		env_node_free(p_env);
		p_env = p_next;
	}
}
