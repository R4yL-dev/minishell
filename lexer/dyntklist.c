/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dyntklist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 21:36:38 by lray              #+#    #+#             */
/*   Updated: 2023/08/11 23:27:15 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_dyntklist	*dyntklist_init(t_dyntklist *tklist)
{
	if (tklist == NULL)
	{
		tklist = malloc(sizeof(t_dyntklist) * 1);
		if (tklist == NULL)
			return (NULL);
		tklist->array = malloc(sizeof(t_token) * 1);
		if (tklist->array == NULL)
			return (NULL);
		tklist->array[0] = NULL;
		tklist->size = 0;
	}
	return (tklist);
}

int	dyntklist_add(t_dyntklist *tklist, int type, char *value)
{
	int actual_size;

	if (tklist == NULL || value == NULL)
		return (0);
	actual_size = ((int) tklist->size) + 1;
	tklist->array = ft_realloc(tklist->array, sizeof(t_token) * actual_size, sizeof(t_token) * (actual_size + 1));
	tklist->array[actual_size - 1]= token_new(type, value);
	tklist->array[actual_size] = NULL;
	tklist->size++;
	return (1);
}

void	dyntklist_show(t_dyntklist *tklist)
{
	int	i;

	if (tklist != NULL)
	{
		i = 0;
		printf("tklist->size : %ld\n", tklist->size);
		while (tklist->array[i])
		{
			printf("tklist->array[%d]->type : %d\n", i, tklist->array[i]->type);
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
