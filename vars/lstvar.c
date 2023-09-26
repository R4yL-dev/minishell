/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstvar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:11:12 by lray              #+#    #+#             */
/*   Updated: 2023/09/26 20:31:46 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	add_envp(t_lstvar *lstvar, char **envp);

t_lstvar	*lstvar_init(char **envp)
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
	if (envp)
		add_envp(new, envp);
	return (new);
}

int	lstvar_add(t_lstvar *lstvar, t_var *var)
{
	size_t	pos;

	if (lstvar == NULL || var == NULL)
		return (0);
	pos = lstvar_has(lstvar, var->name);
	if ((int)pos == -1)
	{
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
	}
	else
	{
		var_free(lstvar->array[pos]);
		lstvar->array[pos] = var;
	}
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
		if (ft_strncmp(name, lstvar->array[pos]->name, ft_strlen(name)) == 0 &&\
			ft_strlen(name) == ft_strlen(lstvar->array[pos]->name))
			return (pos);
		++pos;
	}
	return (-1);
}

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

static int	add_envp(t_lstvar *lstvar, char **envp)
{
	int	i;
	char	*name;
	char	*value;
	char	*equal;
	(void)	lstvar;

	i = 0;
	while (envp[i])
	{
		equal = ft_strchr(envp[i], '=');
		if (equal)
		{
			*equal = '\0';
			name = envp[i];
			value = equal + 1;
			lstvar_add(lstvar, var_new(name, value));
		}
		else
		{
			ft_puterror("lstvar initialization has failed with envp");
			return (0);
		}
		++i;
	}
	return (1);
}
