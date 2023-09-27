/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:04:59 by lray              #+#    #+#             */
/*   Updated: 2023/09/26 21:31:31 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	**make_paths(t_dynarrstr *dynarr, t_grpvar *grpvar);
static int	is_an_executable(char *path);

int	get_cmd_path(t_dynarrstr *dynarr, t_grpvar *grpvar)
{
	char	**paths;
	int		i;

	if (is_an_executable(dynarr->array[0]) == 1)
		return (1);
	paths = make_paths(dynarr, grpvar);
	if (!paths)
	{
		printf("%s: command not found\n", dynarr->array[0]);
		return (0);
	}
	i = 0;
	while (paths[i] != NULL && is_an_executable(paths[i]) == 0)
		i++;
	if (paths[i] == NULL)
	{
		printf("%s: command not found\n", dynarr->array[0]);
		free_split(paths);
		return (0);
	}
	free(dynarr->array[0]);
	dynarr->array[0] = ft_strdup(paths[i]);
	free_split(paths);
	return (1);
}

static char	**make_paths(t_dynarrstr *dynarr, t_grpvar *grpvar)
{
	char	**paths;
	char	**paths_swap;
	int		i;

	paths = get_path(grpvar);
	paths_swap = get_path(grpvar);
	if (paths == NULL || paths_swap == NULL)
		return (NULL);
	i = 0;
	while (paths[i] != NULL)
	{
		free(paths_swap[i]);
		paths_swap[i] = ft_strjoin(paths[i], "/");
		free(paths[i]);
		paths[i] = ft_strjoin(paths_swap[i], dynarr->array[0]);
		free(paths_swap[i]);
		i++;
	}
	free(paths_swap);
	return (paths);
}

static int	is_an_executable(char *path)
{
	if (access(path, (F_OK | X_OK)) == -1)
		return (0);
	return (1);
}
