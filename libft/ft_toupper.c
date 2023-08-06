/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_touppper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:10:34 by luca              #+#    #+#             */
/*   Updated: 2022/09/30 19:10:44 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* Cette fonction met en majuscule les caractères minuscule.
* Si le caractère n'est pas une minuscule, la fonction le retour.
*/

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
