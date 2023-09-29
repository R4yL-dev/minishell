/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 21:58:35 by lray              #+#    #+#             */
/*   Updated: 2023/09/29 19:38:52 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_split(char **splitted_arr)
{
	size_t	i;

	i = 0;
	while (splitted_arr[i])
		free(splitted_arr[i++]);
	free(splitted_arr);
}

char	**arrcpy(char **arr, int size)
{
	char	**new_arr;
	int		i;

	new_arr = malloc (sizeof(char *) * (size + 1));
	if (new_arr == NULL)
	{
		ft_puterror("Malloc failed");
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		new_arr[i] = ft_strdup(arr[i]);
		if (new_arr[i] == NULL)
		{
			ft_puterror("Dup failed");
			return (NULL);
		}
		i++;
	}
	new_arr[i] = NULL;
	return (new_arr);
}

void	ft_puterror(char *msg)
{
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
}

char	*add_char_to_string(char *str, char c)
{
	size_t	len;

	len = ft_strlen(str) + 1;
	str = ft_realloc(str, len, len + 1);
	if (!str)
		return (NULL);
	str[len - 1] = c;
	str[len] = '\0';
	return (str);
}
