/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 22:19:41 by lray              #+#    #+#             */
/*   Updated: 2023/08/18 17:39:11 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	open_file(char *path, int flag, int file_perm);
static t_dynarrstr	*exec_make_argv(t_dyntree *root);
static int	exec_find_cmd(t_dynarrstr *dynarr);
static int	is_cmd(char *path);

/*
	TODO:
		THIS FILE IS HORRIBLE BUT IT WORKS FINE.
		IT'S MUST BE CLEANED BEFORE IT BECOMES A MONSTER.
*/

int	exec(t_dyntree *root)
{
	t_dynarrstr	*dynarr;
	pid_t	pid;
	int		fd_in;
	int		fd_out;
	int		i;

	fd_in = STDIN_FILENO;
	fd_out = STDOUT_FILENO;
	i = 0;
	while (i < (int)root->numChildren)
	{	if (root->children[i]->type == TK_REDIRECTION)
		{
			if (ft_strncmp(root->children[i]->value, "<", 1) == 0)
			{
				fd_in = open_file(root->children[i]->children[0]->value, O_RDONLY, 0);
				if (fd_in == -1)
					return (0);
			}
			else if (ft_strncmp(root->children[i]->value, ">", 1) == 0)
			{
				fd_out = open_file(root->children[i]->children[0]->value, O_WRONLY | O_CREAT | O_TRUNC, 0644);
				if (fd_out == -1)
					return (0);
			}
		}
		i++;
	}
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
	{
		dup2(fd_in, STDIN_FILENO);
		dup2(fd_out, STDOUT_FILENO);
		execve(dynarr->array[0], dynarr->array, NULL);
	}
	else
		wait(NULL);
	dynarrstr_free(dynarr);
	if (fd_in != STDIN_FILENO)
		close(fd_in);
	if (fd_out != STDOUT_FILENO)
		close(fd_out);
	return (1);
}

static int	open_file(char *path, int flag, int file_perm)
{
	int	fd;

	if (file_perm == 0)
		fd = open(path, flag);
	else
		fd = open(path, flag, file_perm);
	if (fd == -1)
	{
		perror("miniShrek");
		return (-1);
	}
	return (fd);
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
				if (root->children[i]->type == TK_ARGUMENT)
				{
					if (dynarrstr_add(dynarr, root->children[i]->value) == 0)
						return (NULL);
				}
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
