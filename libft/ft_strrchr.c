/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:27:02 by luca              #+#    #+#             */
/*   Updated: 2022/10/27 15:33:37 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* La fonction ft_strrchr retourne un pointer sur la dernière occurance
*	du caractère c dans la string s.
* Si la fonction ne trouve pas c dans s, elle retourn NULL.
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*resp;

	resp = NULL;
	while (*s)
	{
		if (*s == (char)c)
			resp = (char *)s;
		s++;
	}
	if ((char)c == '\0')
		resp = (char *)s;
	return (resp);
}
