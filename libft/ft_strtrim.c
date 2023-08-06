/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:28:02 by lray              #+#    #+#             */
/*   Updated: 2023/02/20 23:15:40 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Desc :
		Alloue et retourne une coipe de la chaine s1, sans les caractères dans
		set au début et à la fin de la chaine de caractères.

	Params :
		- s1 : La chaine de caractères à trimmer
		- set : Le set de référence de caractères à trimmer.

	Ret :
		- La chaine de caractères trimmée
		- NULL si l'allocation échoue
*/

#include "libft.h"

static int	in_set(const char *set, char c);
static char	*make_str(const char *s1, size_t start, size_t end);

char	*ft_strtrim(const char *s1, const char *set)
{
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(s1) - 1;
	if (ft_strlen(s1) == 0)
		return (ft_calloc(1, 1));
	while (in_set(set, s1[i]))
		i++;
	while (in_set(set, s1[j]))
		j--;
	return (make_str(s1, i, j - (i - 1)));
}

static char	*make_str(const char *s1, size_t start, size_t len)
{
	char	*resp;
	size_t	i;

	if (len <= 0 || start >= ft_strlen(s1))
		return (ft_strdup(""));
	resp = ft_calloc(len + 1, sizeof(char));
	if (!resp)
		return (NULL);
	i = 0;
	while (i < len)
	{
		resp[i] = s1[start + i];
		i++;
	}
	resp[i] = 0;
	return (resp);
}

static int	in_set(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}
