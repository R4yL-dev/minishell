/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:38:07 by luca              #+#    #+#             */
/*   Updated: 2022/10/25 16:35:32 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* La fonction ft_strncmp compare les n premier caractères des
*	deux strings s1 et s2.
*
* Elle retourne :
*	0, si s1 et s2 sont égale.
*	un nombre négatif si s1 est plus petit que s2.
*	un nombre positif si s1 est plus grand que s2.
* Les nombres renvoyés sont la différance entre les valeurs ascii
*	des premières caractères différants entre les deux chaine.
*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (n-- != 0)
	{
		if (*s1 != *s2++)
			return (*(unsigned char *)s1 - *(unsigned char *)--s2);
		if (*s1++ == 0)
			break ;
	}
	return (0);
}
