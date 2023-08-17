/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 22:19:41 by lray              #+#    #+#             */
/*   Updated: 2023/08/18 00:44:36 by mflury           ###   ########.fr       */
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
	char	**paths;
	int		i;

	paths = get_path();
	if (!paths)
	{
		ft_puterror("get_path failed");
		return (1);
	}
	i = 0;
	if (is_cmd(dynarr->array[0]) == 1)
	{
		free_path(paths);
		return (1);
	}
	i = 0;
	// BON GROS LEAKS SA MERE JUSTE EN DESSOUS !!!!!!!!!!!!!!!!!!!!!!!!!!!!
	while (paths[i])
	{
		paths[i] = ft_strjoin(paths[i], "/");
		paths[i] = ft_strjoin(paths[i], dynarr->array[0]);
		i++;
	}
	paths[i] = NULL;
	i = 0;
	while (is_cmd(paths[i]) == 0 && paths[i])
		i++;
	if (paths[i] == NULL)
		return (0);
	free(dynarr->array[0]);
	dynarr->array[0] = ft_strdup(paths[i]);
	free_path(paths);
	return (1);
}

static int	is_cmd(char *path)
{
	if (access(path, F_OK) == -1 || access(path, X_OK) == -1)
		return (0);
	return (1);
}
