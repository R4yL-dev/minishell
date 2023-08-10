/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 22:19:41 by lray              #+#    #+#             */
/*   Updated: 2023/08/10 15:30:43 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	is_cmd(char *path);

void	exec(char **cmd, char **envp)
{
	pid_t	pid;
	char	*tmp;

	tmp = ft_strjoin("/bin/", cmd[0]);
	free(cmd[0]);
	cmd[0] = tmp;
	if (is_cmd(cmd[0]) == 0)
	{
		printf("Unknow cmd\n");
		return ;
	}
	pid = fork();
	if (pid == -1)
	{
		printf("Fork error.\n");
		return ;
	}
	if (pid == 0)
		execve(cmd[0], cmd, envp);
	else
	{
		wait(NULL);
	}
}

//a function who

static int	is_cmd(char *path)
{
	if (access(path, F_OK) == -1 || access(path, X_OK) == -1)
		return (0);
	return (1);
}
