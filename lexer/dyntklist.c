/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dyntklist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 21:36:38 by lray              #+#    #+#             */
/*   Updated: 2023/09/05 15:29:37 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
	TODO:
		- Il faut que je traite les erreurs ici et pas plus tard
*/

t_dyntklist	*dyntklist_init(t_dyntklist *tklist)
{
	if (tklist == NULL)
	{
		tklist = malloc(sizeof(t_dyntklist) * 1);
		if (tklist == NULL)
		{
			ft_puterror("Malloc failed");
			return (NULL);
		}
		tklist->array = malloc(sizeof(t_token) * 1);
		if (tklist->array == NULL)
		{
			ft_puterror("Malloc failed");
			return (NULL);
		}
		tklist->array[0] = NULL;
		tklist->size = 0;
	}
	return (tklist);
}

int	dyntklist_add(t_dyntklist *tklist, int type, char *value)
{
	int	actual_size;

	if (tklist == NULL || value == NULL)
	{
		ft_puterror("tklist or value cannot be NULL");
		return (0);
	}
	actual_size = ((int) tklist->size) + 1;
	tklist->array = ft_realloc(tklist->array, sizeof(t_token) * actual_size, sizeof(t_token) * (actual_size + 1));
	if (tklist->array == NULL)
	{
		ft_puterror("Realloc failed");
		return (0);
	}
	tklist->array[actual_size - 1] = token_new(type, value);
	tklist->array[actual_size] = NULL;
	tklist->size++;
	return (1);
}

int dyntklist_delone(t_dyntklist *tklist, int id)
{
	int	i;

	if (tklist == NULL || id < 0 || id >= (int)tklist->size)
		return (0);
	token_free(tklist->array[id]);
	i = id;
	while (i < (int)tklist->size - 1)
	{
		tklist->array[i] = tklist->array[i + 1];
		i++;
	}
	tklist->size--;
	if (tklist->size > 0)
		tklist->array = ft_realloc(tklist->array, sizeof(t_token) * (tklist->size + 1), sizeof(t_token) * tklist->size);
	if (tklist->array == NULL)
	{
		ft_puterror("Realloc failed");
		return (0);
	}
	tklist->array[tklist->size] = NULL;
	return (1);
}

void	dyntklist_show(t_dyntklist *tklist)
{
	int	i;

	if (tklist != NULL && tklist->array)
	{
		i = 0;
		printf("tklist->size : %ld\n", tklist->size);
		while (tklist->array[i])
		{
			printf("tklist->array[%d]->type : ", i);
			if (tklist->array[i]->type == 0)
				printf("TK_COMMAND\n");
			else if (tklist->array[i]->type == 1)
				printf("TK_ARGUMENT\n");
			else if (tklist->array[i]->type == 2)
				printf("TK_FILE\n");
			else if (tklist->array[i]->type == 3)
				printf("TK_REDIRECTION\n");
			else if (tklist->array[i]->type == 4)
				printf("TK_PIPE\n");
			printf("tklist->array[%d]->value : %s\n", i, tklist->array[i]->value);
			i++;
		}
	}
}

void	dyntklist_free(t_dyntklist *tklist)
{
	int	i;

	i = 0;
	if (tklist != NULL)
	{
		if (tklist->array != NULL)
		{
			while (i < (int)(tklist->size + 1))
			{
				token_free(tklist->array[i]);
				i++;
			}
			free(tklist->array);
		}
		free(tklist);
	}
}
