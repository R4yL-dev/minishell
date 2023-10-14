/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:04:59 by lray              #+#    #+#             */
/*   Updated: 2023/10/14 15:49:16 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


static char	**get_all_paths(t_grpvar *grpvar);
static char	*is_cmd(char *cmd, char **paths);
static char	*make_path(char *path, char *cmd);
static int	end_by_slash(char *path);
static int	is_an_executable(char *path);

char	*get_cmd_path(char *cmd, t_grpvar *grpvar)
{
	char	**paths;
	char	*res;

	paths = NULL;
	res = NULL;
	if (is_an_executable(cmd))
		return(ft_strdup(cmd));
	paths = get_all_paths(grpvar);
	res = is_cmd(cmd, paths);
	if (paths)
		free_split(paths);
	return (res);
}

static char	**get_all_paths(t_grpvar *grpvar)
{
	char	**res;
	size_t	pos;

	pos = grpvar_has(grpvar, GRPVAR_GLOBAL, "PATH");
	if ((int)pos == -1)
		return (NULL);
	res = ft_split(grpvar->global->array[pos]->value, ':');
	return (res);
}

static char	*is_cmd(char *cmd, char **paths)
{
	size_t	i_path;
	char	*path;

	if (cmd == NULL || paths == NULL)
		return (NULL);
	i_path = 0;
	while (paths[i_path])
	{
		path = make_path(paths[i_path], cmd);
		if (is_an_executable(path))
			return(path);
		free (path);
		++i_path;
	}
	return (NULL);
}

static char	*make_path(char *path, char *cmd)
{
	int		end_slash;
	size_t	len_str;
	char	*res;

	res = NULL;
	end_slash = end_by_slash(path);
	if (end_slash == 0)
		len_str = ft_strlen(path) + ft_strlen(cmd) + 2;
	else
		len_str = ft_strlen(path) + ft_strlen(cmd) + 1;
	res = malloc(sizeof(char) * len_str);
	if (!res)
	{
		ft_puterror("Malloc failed");
		return (NULL);
	}
	ft_strlcpy(res, path, ft_strlen(path) + 1);
	if (end_slash == 0)
	{
		res[ft_strlen(path)] = '/';
		res[ft_strlen(path) + 1] = '\0';
	}
	ft_strlcat(res, cmd, len_str);
	return (res);
}

static int	end_by_slash(char *path)
{
	size_t	path_len;

	if (path == NULL)
		return (0);
	path_len = ft_strlen(path);
	if (path[path_len - 1] == '/')
		return (1);
	return (0);
}

static int	is_an_executable(char *path)
{
	struct stat	sb;

	if (stat(path, &sb) == -1)
	{
		ft_puterror("Stat failed");
		return (0);
	}
	if (S_ISDIR(sb.st_mode))
		return (0);
	if (access(path, (F_OK | X_OK)) == -1)
		return (0);
	return (1);
}
