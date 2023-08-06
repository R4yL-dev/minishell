/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:08:27 by lray              #+#    #+#             */
/*   Updated: 2022/11/02 00:30:29 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* La fonction ft_memcmp() compare les n premiers octets
*	(chacun interprété comme unsigned char) des zones mémoire s1 et s2.
*
* La fonction memcmp() renvoie un entier inférieur, égal ou supérieur
*	à zéro si les n premiers octets de s1 sont respectivement
*	inférieurs, égaux ou supérieurs aux n premiers octets de s2.
* Lorsque la valeur renvoyée est différente de zéro, elle est de même
*	signe que la différence entre les deux premiers octets
*	(interprétés comme unsigned  char) qui diffèrent dans s1 et s2.
* Lorsque la valeur renvoyée est différente de zéro, elle est de même
*	signe que la différence entre les deux premiers octets
*	(interprétés comme unsigned  char) qui diffèrent dans s1 et s2.
*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptr_s1;
	const unsigned char	*ptr_s2;

	ptr_s1 = s1;
	ptr_s2 = s2;
	while (n--)
	{
		if (*ptr_s1 != *ptr_s2)
			return (*ptr_s1 - *ptr_s2);
		else
		{
			ptr_s1++;
			ptr_s2++;
		}
	}
	return (0);
}
