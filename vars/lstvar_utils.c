/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstvar_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:58:28 by lray              #+#    #+#             */
/*   Updated: 2023/10/31 20:58:55 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	lstvar_remove(t_lstvar *lstvar, size_t index)
{
	size_t	i;

	if (lstvar == NULL || (int)index >= (int)lstvar->num_elements)
	{
		ft_puterror("Element to be deleted does not exist");
		return (-1);
	}
	if ((int)index == -1)
		return (-1);
	var_free(lstvar->array[index]);
	i = index;
	while (i < lstvar->num_elements - 1)
	{
		lstvar->array[i] = lstvar->array[i + 1];
		++i;
	}
	lstvar->num_elements--;
	return (lstvar->num_elements);
}

void	lstvar_free(t_lstvar *lstvar)
{
	size_t	i;

	if (lstvar)
	{
		if (lstvar->array)
		{
			if (lstvar->num_elements > 0)
			{
				i = 0;
				while (i < lstvar->num_elements)
				{
					var_free(lstvar->array[i]);
					lstvar->array[i] = NULL;
					++i;
				}
			}
			free(lstvar->array);
			lstvar->array = NULL;
		}
		free(lstvar);
		lstvar = NULL;
	}
}
