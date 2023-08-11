/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 22:19:41 by lray              #+#    #+#             */
/*   Updated: 2023/08/11 19:39:57 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	is_cmd(char *path);

void exec(t_tree_node *tree)
{
	t_dynarrstr	*dynarr;
	pid_t	pid;
	char	*tmp;
	int		i;

	dynarr = NULL;
	dynarr = dynarrstr_init(dynarr);
	dynarrstr_add(dynarr, tree->value);
	i = 0;
	while (tree->children[i])
	{
		dynarrstr_add(dynarr, tree->children[i]->value);
		i++;
	}
	tmp = ft_strjoin("/bin/", dynarr->array[0]);
	free(dynarr->array[0]);
	dynarr->array[0] = tmp;
	if (is_cmd(dynarr->array[0]) == 0)
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
		execve(dynarr->array[0], dynarr->array, NULL);
	else
		wait(NULL);
	dynarrstr_free(dynarr);
}

static int	is_cmd(char *path)
{
	if (access(path, F_OK) == -1 || access(path, X_OK) == -1)
		return (0);
	return (1);
}
