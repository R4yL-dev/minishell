/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:08:48 by lray              #+#    #+#             */
/*   Updated: 2023/02/20 23:15:18 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Desc :
		Alloue et retourne une nouvelle chaine, résultat de la concaténation
		de s1 et s2

	Params :
		- s1 : La chaine de caractères préfixe
		- s2 : La chaine de caractères suffixe.

	Ret :
		- La nouvelle chaine de caractères.
		- NULL si l'allocation échoue
*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*resp;
	size_t	i;

	resp = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!resp)
		return (NULL);
	i = 0;
	while (*s1)
	{
		resp[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		resp[i] = *s2;
		i++;
		s2++;
	}
	resp[i] = '\0';
	return (resp);
}
