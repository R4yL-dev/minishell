/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstvar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:11:12 by lray              #+#    #+#             */
/*   Updated: 2023/09/26 17:40:29 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_lstvar	*lstvar_init(void)
{
	t_lstvar	*new;

	new = malloc(sizeof(t_lstvar) * 1);
	if (!new)
	{
		ft_puterror("Malloc failed");
		return (NULL);
	}
	new->num_elements = 0;
	new->capacity = LSTVAR_INITIAL_CAP;
	new->array = malloc(sizeof(t_var) * new->capacity);
	if (!new->array)
	{
		ft_puterror("Malloc failed");
		return (NULL);
	}
	return (new);
}

int	lstvar_add(t_lstvar *lstvar, t_var *var)
{
	if (lstvar == NULL || var == NULL)
		return (0);
	if (lstvar->num_elements == lstvar->capacity)
	{
		lstvar->capacity *= 2;
		lstvar->array = ft_realloc(lstvar->array, lstvar->capacity / 2 * sizeof(t_var), lstvar->capacity * sizeof(t_var));
		if (!lstvar->array)
		{
			ft_puterror("Realloc failed");
			return (0);
		}
	}
	lstvar->array[lstvar->num_elements] = var;
	lstvar->num_elements++;
	return (1);
}

void	lstvar_show(t_lstvar *lstvar)
{
	size_t	i;

	if (lstvar)
	{
		i = 0;
		while (i < lstvar->num_elements)
		{
			var_show(lstvar->array[i]);
			++i;
		}
	}
}

size_t	lstvar_has(t_lstvar *lstvar, char *name)
{
	size_t	pos;

	pos = 0;
	while (pos < lstvar->num_elements)
	{
		if (ft_strncmp(name, lstvar->array[pos]->name, ft_strlen(name)) == 0)
			return (pos);
		++pos;
	}
	return (-1);
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
