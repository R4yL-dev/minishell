/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:24:32 by lray              #+#    #+#             */
/*   Updated: 2023/10/31 18:30:04 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	**realloc_if_too_small(char **value, int len_new, int len_value);
static char	**process_replace(size_t *lens, char **value, int *i, char *res);

char	*search_and_replace(char **value, char *varname, char *res, int *i)
{
	size_t	lens[4];

	lens[0] = ft_strlen(*value);
	lens[1] = ft_strlen(varname);
	if (!res)
		lens[2] = 0;
	else
		lens[2] = ft_strlen(res);
	lens[3] = lens[0] - lens[1] + lens[2];
	if (lens[3] == 0)
	{
		*value[*i] = '\0';
		return (*value);
	}
	realloc_if_too_small(value, lens[3], lens[0]);
	if (value == NULL)
		return (NULL);
	value = process_replace(lens, value, i, res);
	return (*value);
}

static char	**realloc_if_too_small(char **value, int len_new, int len_value)
{
	if (len_new > len_value)
	{
		*value = ft_realloc(*value, \
		sizeof(char) * len_value + 1, sizeof(char) * (len_new * 2));
		if (*value == NULL)
		{
			ft_puterror("Realloc failed");
			return (NULL);
		}
	}
	return (value);
}

static char	**process_replace(size_t *lens, char **value, int *i, char *res)
{
	char	*src;
	char	*dst;

	src = *value + *i + lens[1];
	dst = *value + *i + lens[2];
	if (lens[2] == 0)
		ft_memmove(dst, src, ft_strlen(src));
	else if (lens[2] > lens[1])
	{
		ft_memmove(dst, src, lens[2]);
		ft_memcpy(*value + *i, res, lens[2]);
	}
	else if (lens[2] < lens[1])
	{
		ft_memcpy(*value + *i, res, lens[2]);
		ft_memmove(dst, src, ft_strlen(dst));
	}
	ft_memset(*value + lens[3], '\0', 1);
	if (lens[2] > 0)
		(*i) += lens[2] -1;
	else
		(*i)--;
	return (value);
}
