/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:49:07 by lray              #+#    #+#             */
/*   Updated: 2023/08/24 19:20:42 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static t_dynarrstr	*make_argv(t_dyntree *root);

t_env_node	*env_node_init(t_dyntree *root, int **pipes_list, int num_env)
{
	t_env_node	*head;
	t_env_node	*prev;
	int			i;
	t_dynarrstr	*args;

	if (num_env < 1)
		return (NULL);
	head = NULL;
	head = env_node_new();
	if (root->type == TK_COMMAND)
	{
		if (open_all_fd(root, &head->fd_in, &head->fd_out) == 0)
		{
			env_node_freeall(head);
			return (NULL);
		}
		args = make_argv(root);
		if (get_cmd_path(args) == 0)
		{
			dynarrstr_free(args);
			env_node_freeall(head);
			return (NULL);
		}
		head->path = ft_strdup(args->array[0]);
		head->args = arrcyp(args->array, args->size);
		dynarrstr_free(args);
		return (head);
	}

	prev = head;
	i = 0;
	while (i < num_env - 1)
	{
		if (i != 0)
		{
			prev->fd_in = pipes_list[i - 1][0];
			prev->fd_out = pipes_list[i][1];
		}
		else
		{
			prev->fd_out = pipes_list[i][1];
		}
		if (open_all_fd(root->children[i], &prev->fd_in, &prev->fd_out) == 0)
		{
			env_node_freeall(head);
			return (NULL);
		}
		args = make_argv(root->children[i]);
		if (get_cmd_path(args) == 0)
		{
			dynarrstr_free(args);
			env_node_freeall(head);
			return (NULL);
		}
		prev->path = ft_strdup(args->array[0]);
		prev->args = arrcyp(args->array, args->size);
		dynarrstr_free(args);
		prev->next = env_node_new();
		prev = prev->next;
		i++;
	}
	prev->fd_in = pipes_list[i - 1][0];
	if (open_all_fd(root->children[i], &prev->fd_in, &prev->fd_out) == 0)
	{
		env_node_freeall(head);
		return (NULL);
	}
	args = make_argv(root->children[i]);
	if (get_cmd_path(args) == 0)
	{
			dynarrstr_free(args);
			env_node_freeall(head);
			ft_puterror("Command not found");
			return (NULL);
	}
	prev->path = ft_strdup(args->array[0]);
	prev->args = arrcyp(args->array, args->size);
	dynarrstr_free(args);
	return (head);
}

t_env_node	*env_node_new(void)
{
	t_env_node *new_node;

	new_node = malloc(sizeof(t_env_node) * 1);
	if (new_node == NULL)
	{
		ft_puterror("Malloc failed");
		return (NULL);
	}
	new_node->path = NULL;
	new_node->args = NULL;
	new_node->fd_in = STDIN_FILENO;
	new_node->fd_out = STDOUT_FILENO;
	new_node->next = NULL;
	return (new_node);
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
		printf("path : %s\n", node->path);
		i = 0;
		printf("Argument :\n");
		while (node->args[i])
			printf("\t%s\n", node->args[i++]);
		printf("fd_in : %d\n", node->fd_in);
		printf("fd_out : %d\n", node->fd_out);
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
		free(node);
		node = NULL;
	}
}

void	env_node_freeall(t_env_node *head)
{
	t_env_node	*next;

	if (head != NULL)
	{
		while (head != NULL)
		{
			next = head->next;
			env_node_free(head);
			head = next;
		}
		free(head);
		head = NULL;
	}
}

static t_dynarrstr	*make_argv(t_dyntree *root)
{
	t_dynarrstr	*dynarr;
	size_t		i;

	dynarr = NULL;
	dynarr = dynarrstr_init(dynarr);
	if (dynarr == NULL)
		return (NULL);
	if (root && root->value)
	{
		if (dynarrstr_add(dynarr, root->value) == 0)
			return (NULL);
		i = 0;
		while (i < root->numChildren)
		{
			if (root->children[i]->type == TK_ARGUMENT)
			{
				if (dynarrstr_add(dynarr, root->children[i]->value) == 0)
					return (NULL);
			}
			i++;
		}
	}
	else
		return (NULL);
	return (dynarr);
}
