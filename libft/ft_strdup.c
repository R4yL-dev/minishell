/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:33:57 by lray              #+#    #+#             */
/*   Updated: 2023/02/20 23:15:10 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		size;
	int		i;
	char	*resp;

	size = ft_strlen(s);
	resp = (char *)malloc(sizeof(char) * (size + 1));
	if (resp == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		*(resp + i) = *(char *)(s + i);
		i++;
	}
	resp[i] = '\0';
	return (resp);
}
