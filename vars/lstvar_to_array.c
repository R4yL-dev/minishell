/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstvar_to_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:33:25 by lray              #+#    #+#             */
/*   Updated: 2023/10/07 16:09:36 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*make_value(char *res, char *name, char *value);

t_dynarrstr	*lstvar_to_array(t_lstvar *lstvar)
{
	t_dynarrstr	*res;
	size_t		i;
	(void)		lstvar;
	char		*value;

	res = NULL;
	value = NULL;
	if (lstvar == NULL)
		return (NULL);
	res = dynarrstr_init(res);
	i = 0;
	while (i < lstvar->num_elements)
	{
		value = make_value(value, lstvar->array[i]->name, lstvar->array[i]->value);
		dynarrstr_add(res, value);
		free(value);
		value = NULL;
		++i;
	}
	return (res);
}

static char	*make_value(char *res, char *name, char *value)
{
	size_t	name_len;
	size_t	value_len;
	size_t	res_len;

	if (res != NULL || name == NULL || value == NULL)
		return (NULL);
	name_len = ft_strlen(name);
	value_len = ft_strlen(value);
	res_len = name_len + value_len + 2;
	res = malloc(sizeof(char) + res_len);
	if (!res)
	{
		ft_puterror("Malloc failed");
		return (NULL);
	}
	ft_bzero(res, sizeof(char) + res_len);
	ft_strlcpy(res, name, res_len);
	ft_strlcat(res, "=", res_len);
	ft_strlcat(res, value, res_len);
	return (res);
}
