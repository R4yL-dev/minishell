/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_all_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:25:36 by lray              #+#    #+#             */
/*   Updated: 2023/09/19 19:14:02 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	get_fd(char *token, char *path, int *fd_in, int *fd_out);
static int	open_file_rd(char *path);
static int	open_file_wr(char *path);
static int	open_file_wra(char *path);
static int	open_file(char *path, int flag, int file_perm);

int	open_all_fd(t_dyntree *root, int *fd_in, int *fd_out)
{
	int	i;

	i = 0;
	if (root->type == TK_REDIRECTION)
	{
		if (get_fd(root->value, root->children[0]->value,  fd_in, fd_out) == 0)
			return (0);
		i++;
	}
	while (i < (int)root->numChildren)
	{
		if (root->children[i]->type == TK_REDIRECTION)
		{
			if (get_fd(root->children[i]->value, \
				root->children[i]->children[0]->value, fd_in, fd_out) == 0)
				return (0);
		}
		i++;
	}
	return (1);
}

static int	get_fd(char *token, char *path, int *fd_in, int *fd_out)
{
	if (ft_strlen(token) == 1 && ft_strncmp(token, "<", 1) == 0)
	{
		*fd_in = open_file_rd(path);
		if (*fd_in == -1)
			return (0);
	}
	else if (ft_strlen(token) == 1 && ft_strncmp(token, ">", 1) == 0)
	{
		*fd_out = open_file_wr(path);
		if (*fd_out == -1)
			return (0);
	}
	else if (ft_strlen(token) == 2 && ft_strncmp(token, ">>", 2) == 0)
	{
		*fd_out = open_file_wra(path);
		if (*fd_out == -1)
			return (0);
	}
	return (1);
}

static int	open_file_rd(char *path)
{
	int	fd;

	fd = open_file(path, O_RDONLY, 0);
	return (fd);
}

static int	open_file_wr(char *path)
{
	int	fd;

	fd = open_file(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	return (fd);
}

static int	open_file_wra(char *path)
{
	int	fd;

	fd = open_file(path, O_WRONLY | O_CREAT | O_APPEND, 0644);
	return (fd);
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
		perror(path);
		return (-1);
	}
	return (fd);
}
