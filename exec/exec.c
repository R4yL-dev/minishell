/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 22:19:41 by lray              #+#    #+#             */
/*   Updated: 2023/08/13 19:53:15 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static t_dynarrstr	*exec_make_argv(t_dyntree *root);
static int	exec_find_cmd(t_dynarrstr *dynarr);
static int	is_cmd(char *path);

/*
	TODO:
		. Check PATH to find cmd
*/

void	exec(t_dyntree *root)
{
	t_dynarrstr	*dynarr;
	pid_t	pid;

	dynarr = exec_make_argv(root);
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

static t_dynarrstr	*exec_make_argv(t_dyntree *root)
{
	t_dynarrstr	*dynarr;
	size_t			i;

	dynarr = NULL;
	dynarr = dynarrstr_init(dynarr);
	if (root && root->value)
	{
		dynarrstr_add(dynarr, root->value);
		if (dynarr->array)
		{
			i = 0;
			while (i < root->numChildren)
			{
				dynarrstr_add(dynarr, root->children[i]->value);
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
