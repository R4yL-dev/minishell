/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:25:36 by lray              #+#    #+#             */
/*   Updated: 2023/10/03 22:49:59 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	open_file(char *path, int flag, int file_perm);

int	open_file_rd(char *path)
{
	int	fd;

	fd = open_file(path, O_RDONLY, 0);
	return (fd);
}

int	open_file_wr(char *path)
{
	int	fd;

	fd = open_file(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	return (fd);
}

int	open_file_wra(char *path)
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
