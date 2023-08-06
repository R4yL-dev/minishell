/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:36:28 by lray              #+#    #+#             */
/*   Updated: 2022/11/08 11:22:33 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *find, size_t slen)
{
	size_t	i;
	size_t	j;

	if (find[0] == 0)
		return ((char *)s);
	i = 0;
	j = 0;
	while (i < slen && s[i])
	{
		while (s[i + j] == find[j] && s[i + j] && (i + j) < slen)
		{
			j++;
			if (find[j] == '\0')
				return ((char *)s + i);
		}
		i++;
		j = 0;
	}
	return (0);
}
