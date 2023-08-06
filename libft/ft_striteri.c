/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 23:21:53 by lray              #+#    #+#             */
/*   Updated: 2022/11/01 23:39:29 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Desc :
		Applique la fonction f à chaque caractère de la chaine de
		caractères transmise comme argument, et en passant son index
		comme premier argument.
		Chaque caractère est transmis par adresse à f afin d'être
		modifié si nécessaire.

	Params :
		- s : La chaine de caracères sur laquelle itérer.
		- f : La fonction à appliquer à chaque caractère.

	Ret :
		- Aucun
*/

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
