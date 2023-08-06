/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:16:36 by luca              #+#    #+#             */
/*   Updated: 2022/11/07 22:51:41 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* La fonction ft_memcpy() copie n octets depuis la zone mémoire src vers
*	la zone mémoire dest.
* Les deux zones ne doivent pas se chevaucher.
* Si c'est le cas, utilisez plutôt ft_memmove().
*
* Elle retourne un pointeur sur dest.
*/

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*tmp_dest;
	const unsigned char	*tmp_src;

	if (src != dest)
	{
		tmp_dest = dest;
		tmp_src = src;
		while (n--)
			*tmp_dest++ = *tmp_src++;
	}
	return (dest);
}
