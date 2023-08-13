/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 22:19:41 by lray              #+#    #+#             */
/*   Updated: 2023/08/14 01:36:20 by lray             ###   ########.fr       */
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

int	exec(t_dyntree *root)
{
	t_dynarrstr	*dynarr;
	pid_t	pid;

	dynarr = exec_make_argv(root);
	if (dynarr == NULL)
		return (0);
	if (exec_find_cmd(dynarr) == 0)
	{
		ft_puterror("Commande not found");
		dynarrstr_free(dynarr);
		return (0);
	}
	pid = fork();
	if (pid == -1)
	{
		ft_puterror("Fork error.\n");
		dynarrstr_free(dynarr);
		return (0);
	}
	if (pid == 0)
		execve(dynarr->array[0], dynarr->array, NULL);
	else
		wait(NULL);
	dynarrstr_free(dynarr);
	return (1);
}

static t_dynarrstr	*exec_make_argv(t_dyntree *root)
{
	t_dynarrstr	*dynarr;
	size_t			i;

	dynarr = NULL;
	dynarr = dynarrstr_init(dynarr);
	if (dynarr == NULL)
		return (NULL);
	if (root && root->value)
	{
		if (dynarrstr_add(dynarr, root->value) == 0)
			return (NULL);
		if (dynarr->array)
		{
			i = 0;
			while (i < root->numChildren)
			{
				if (dynarrstr_add(dynarr, root->children[i]->value) == 0)
					return (NULL);
				i++;
			}
		}
	}
	else
	{
		ft_puterror("Root or root->value cannot be NULL");
		return (NULL);
	}
	return (dynarr);
}

static int	exec_find_cmd(t_dynarrstr *dynarr)
{
	char	*tmp;

	tmp = ft_strjoin("/bin/", dynarr->array[0]);
	if (tmp == NULL)
	{
		ft_puterror("Ft_strjoin failed");
		return (0);
	}
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
