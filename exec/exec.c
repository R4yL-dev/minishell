/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 22:19:41 by lray              #+#    #+#             */
/*   Updated: 2023/08/11 20:24:55 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static t_dynarrstr	*exec_make_argv(t_tree_node *tree);
static int	exec_find_cmd(t_dynarrstr *dynarr);
static int	is_cmd(char *path);

/*
	TODO:
		. Check PATH to find cmd
*/

void exec(t_tree_node *tree)
{
	t_dynarrstr	*dynarr;
	pid_t	pid;

	dynarr = exec_make_argv(tree);
	if (exec_find_cmd(dynarr) == 0)
	{
		dynarrstr_free(dynarr);
		printf("Cmd not found.\n");
		return ;
	}
	pid = fork();
	if (pid == -1)
	{
		printf("Fork error.\n");
		return ;
	}
	if (pid == 0)
		execve(dynarr->array[0], dynarr->array, NULL);
	else
		wait(NULL);
	dynarrstr_free(dynarr);
}

static t_dynarrstr	*exec_make_argv(t_tree_node *tree)
{
	t_dynarrstr	*dynarr;
	int			i;

	dynarr = NULL;
	dynarr = dynarrstr_init(dynarr);
	if (tree && tree->value)
	{
		dynarrstr_add(dynarr, tree->value);
		if (dynarr->array)
		{
			i = 0;
			while (tree->children[i])
			{
				dynarrstr_add(dynarr, tree->children[i]->value);
				i++;
			}
		}
	}
	return (dynarr);
}

static int	exec_find_cmd(t_dynarrstr *dynarr)
{
	char	*tmp;

	tmp = ft_strjoin("/bin/", dynarr->array[0]);
	if (is_cmd(tmp) == 0)
	{
		free(tmp);
		return (0);
	}
	free(dynarr->array[0]);
	dynarr->array[0] = ft_strdup(tmp);
	free(tmp);
	return (1);
}

static int	is_cmd(char *path)
{
	if (access(path, F_OK) == -1 || access(path, X_OK) == -1)
		return (0);
	return (1);
}
