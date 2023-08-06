/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 23:01:37 by lray              #+#    #+#             */
/*   Updated: 2023/02/20 23:15:30 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Desc :
		Applique la fonction f à chaque caractère de la chaine de caractères
		passée en argument pour créer une nouvelle chaine de caractères
		résultant des applications successives de f.

	Params :
		- s : La chaine de caractères sur laquelle itérer.
		- f : La fonction à appliquer à chaque caractère.

	Ret :
		- La chaine de caractères résultant des applications successives de f.
		- NULL si l'allocation échoue.
*/

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*buf;
	size_t	i;

	buf = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!buf)
		return (NULL);
	i = 0;
	while (s[i])
	{
		buf[i] = f(i, s[i]);
		i++;
	}
	buf[i] = '\0';
	return (buf);
}
