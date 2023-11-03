/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:01:45 by mflury            #+#    #+#             */
/*   Updated: 2023/11/02 23:23:55 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

char	**copy_names(t_lstvar *lstvar)
{
	int		i;
	char	**list;

	i = 0;
	list = malloc(sizeof(char *) * lstvar->num_elements);
	while (i < (int)lstvar->num_elements)
	{
		list[i] = ft_strdup(lstvar->array[i]->name);
		i++;
	}
	return (list);
}

char	**sort_names(char **list, t_lstvar *lstvar)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (i < (int)lstvar->num_elements)
	{
		j = 0;
		while (j + 1 < (int)lstvar->num_elements)
		{
			if (ft_strncmp(list[j], list[j + 1], ft_strlen(list[j])) > 0)
			{
				tmp = ft_strdup(list[j]);
				free(list[j]);
				list[j] = ft_strdup(list[j + 1]);
				free(list[j + 1]);
				list[j + 1] = ft_strdup(tmp);
				free (tmp);
				tmp = NULL;
			}
			j++;
		}
		i++;
	}
	return (list);
}

void	call_names_alpha(char **sorted_list, t_lstvar *lstvar)
{
	int	i;
	int	pos;

	pos = -1;
	i = 0;
	while (i < (int)lstvar->num_elements)
	{
		pos = lstvar_has(lstvar, sorted_list[i]);
		free (sorted_list[i]);
		if (lstvar->array[pos]->value)
			printf("declare -x %s=\"%s\"\n",
				lstvar->array[pos]->name, lstvar->array[pos]->value);
		else
			printf("declare -x %s\n", lstvar->array[pos]->name);
		i++;
	}
	free (sorted_list);
}
