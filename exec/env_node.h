/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_node.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:48:33 by lray              #+#    #+#             */
/*   Updated: 2023/08/23 15:44:48 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_NODE_H
# define ENV_NODE_H

typedef struct s_env_node
{
	char				*path;
	char				**args;
	int					fd_in;
	int					fd_out;
	struct s_env_node	*next;
}	t_env_node;

t_env_node	*env_node_init(t_dyntree *root, int **pipes_list, int num_env);

/**
 * @brief Creates a new node for a linked list of environment variables.
 *
 * This function creates a new node for a linked list of environment variables,
 * and initializes its fields to default values. If the allocation fails, this
 * function returns `NULL`.
 *
 * @return A pointer to the new node, or `NULL` if the allocation fails.
 */
t_env_node	*env_node_new(void);

/**
 * @brief Counts the number of nodes in a linked list of environment variables.
 *
 * This function counts the number of nodes in a linked list of environment variables,
 * starting from the head node and continuing until the end of the list. If the head
 * node is `NULL`, this function returns `-1`.
 *
 * @param head The head node of the linked list.
 * @return The number of nodes in the linked list, or `-1` if the head node is `NULL`.
 */
int	env_node_count(t_env_node *head);

void	env_node_show(t_env_node *head);

/**
 * @brief Frees a single node in a linked list of environment variables.
 *
 * This function frees a single node in a linked list of environment variables,
 * including its `path` and `args` fields. If the node is `NULL`, this function
 * does nothing.
 *
 * @param node The node to free.
 */
void	env_node_free(t_env_node *node);

/**
 * @brief Frees all nodes in a linked list of environment variables.
 *
 * This function frees all nodes in a linked list of environment variables,
 * starting from the head node and continuing until the end of the list.
 *
 * @param head The head node of the linked list.
 */
void	env_node_freeall(t_env_node *head);

#endif
