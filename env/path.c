/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 21:46:07 by mflury            #+#    #+#             */
/*   Updated: 2023/08/17 03:25:21 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// char	**get_path(char **envp)
// {
// 	char	*path;
// 	char	**paths;
// 	int		i;

// 	i = 0;
// 	path = NULL;
// 	while (envp[i])
// 	{
// 		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
// 			path = ft_strdup(envp[i] + 5);
// 		else
// 			i++;
// 	}
// 	if (!path)
// 		return (NULL);
// 	paths = ft_split(path, ':');
// 	free(path);
// 	return (paths);
// }

int	is_slash(char c)
{
	if (c == '/')
		return (1);
	return (0);
}

int is_only_slash(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (is_slash(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

char	**get_path(void)
{
	char	*path;
	char	**paths;
	
	path = NULL;
	path = getenv("PATH");
	if (!path)
		return (NULL);
	path = ft_strtrim(path, "PATH=");
	paths = ft_split(path, ':');
	free(path);
	return (paths);
}

void free_path(char **paths)
{
	int i;

	i = 0;
	while (paths[i])
		free(paths[i++]);
	free(paths);
}