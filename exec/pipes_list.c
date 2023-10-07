/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:54:30 by lray              #+#    #+#             */
/*   Updated: 2023/10/05 14:22:28 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	**pipes_list_create(int num_pipes)
{
	int	**pipes_list;
	int	i;

	if (num_pipes <= 0)
		return (NULL);
	pipes_list = malloc(sizeof(int *) * num_pipes);
	if (pipes_list == NULL)
	{
		ft_puterror("Malloc error");
		return (NULL);
	}
	i = 0;
	while (i < num_pipes)
	{
		pipes_list[i] = malloc(sizeof(int) * 2);
		if (pipes_list[i] == NULL)
		{
			ft_puterror("Malloc error");
			return (NULL);
		}
		if (pipe(pipes_list[i]) < 0)
		{
			perror("miniShrek");
			return (NULL);
		}
		i++;
	}
	return (pipes_list);
}

void	pipes_list_show(int **pipes_list, int num_pipes)
{
	int	i;
	int	j;

	if (num_pipes <= 0)
		return ;
	printf("Number of pipes : %d\n", num_pipes);
	i = 0;
	while (i < num_pipes)
	{
		printf("pipes[%d] : ", i);
		j = 0;
		while (j < 2)
		{
			if (j == 0)
				printf("fd[0] = %d | ", pipes_list[i][j]);
			else
				printf("fd[1] = %d\n", pipes_list[i][j]);
			j++;
		}
		i++;
	}
}

void	pipes_list_free(int **pipes_list, int num_pipes)
{
	int	i;

	if (num_pipes <= 0)
		return ;
	i = 0;
	while (i < num_pipes)
	{
		close(pipes_list[i][0]);
		close(pipes_list[i][1]);
		free(pipes_list[i]);
		i++;
	}
	free(pipes_list);
}
