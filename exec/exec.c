/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 22:19:41 by lray              #+#    #+#             */
/*   Updated: 2023/08/11 02:43:59 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	**tree_to_argv(t_tree_node *tree);
static int	is_cmd(char *path);

void exec(t_tree_node *tree, char **envp)
{
	char	**argv;
	pid_t	pid;
	char	*tmp;

	argv = tree_to_argv(tree);
	tmp = ft_strjoin("/bin/", argv[0]);
	free(argv[0]);
	argv[0] = tmp;
	if (is_cmd(argv[0]) == 0)
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
		execve(argv[0], argv, envp);
	else
		wait(NULL);
}

/*
	TODO:
		- Gerer les erreurs de malloc
*/
static char	**tree_to_argv(t_tree_node *tree)
{
	char	**resp;
	int		nbr_node;
	int		i;

	resp = NULL;
	nbr_node = tree_count_node(tree);
	if (nbr_node < 1)
		return (NULL);
	resp = malloc(sizeof(char *) * (nbr_node + 1));
	if (resp == NULL)
		return (NULL);

	i = 0;
	resp[i] = malloc(sizeof(char) * ft_strlen(tree->value) + 1);
	resp[i] = ft_strdup(tree->value);
	i++;
	if (nbr_node > 1)
	{
		while (i < nbr_node)
		{
			resp[i] = malloc(sizeof(char) * (ft_strlen(tree->children[i - 1]->value) + 1));
			resp[i] = ft_strdup(tree->children[i - 1]->value);
			i++;
		}
	}
	resp[i] = NULL;

	return (resp);
}

static int	is_cmd(char *path)
{
	if (access(path, F_OK) == -1 || access(path, X_OK) == -1)
		return (0);
	return (1);
}
