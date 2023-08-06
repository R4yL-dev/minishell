/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:26:14 by lray              #+#    #+#             */
/*   Updated: 2023/02/20 23:15:45 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Desc :
		Alloue (avec malloc) et retourne une chaine de caractères
		issue de la chaine 's'.
		Cette nouvelle chaine commence à l'index 'start' et a pour
		taille maximale 'len'.

	Params :
		- s : La chaine de laquelle extraire la nouvelle chaine.
		- start : L'index de début de la nouvelle chaine dans la chaine 's'.
		- len : La taille maximale de la nouvelle chaine.

	Ret :
		- La nouvelle chaine de caractères.
		- NULL si l'allocation échoue.
*/

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_calloc(1, 1));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}
