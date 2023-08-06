/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 18:19:50 by lray              #+#    #+#             */
/*   Updated: 2023/02/20 23:18:21 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* La fonction ft_memmove() copie n octets depuis la zone mémoire src vers la
*	zone mémoire dest.
* Les deux zones peuvent se chevaucher :
*	la copie s'effectue comme si src était d'abord copiée dans un
*	tableau temporaire ne chevauchant pas src ou dest puis copiée vers dest.
*
* La fonction retoure un pointeur sur dest.
*/

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*pt_src;
	char	*pt_dst;

	pt_dst = (char *)dst;
	pt_src = (char *)src;
	if ((pt_src == NULL) && (pt_dst == NULL))
		return (NULL);
	if ((pt_src < pt_dst) && (pt_dst < pt_src + n))
	{
		pt_dst += n;
		pt_src += n;
		while (n)
		{
			*--pt_dst = *--pt_src;
			n--;
		}
	}
	else
	{
		while (n--)
			*pt_dst++ = *pt_src++;
	}
	return (dst);
}
