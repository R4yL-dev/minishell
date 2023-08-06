/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:40:19 by lray              #+#    #+#             */
/*   Updated: 2023/02/20 23:11:47 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Desc :
		Alloue et retourbe une chaine de caractères représentant l'entier n
		reçu en argument.
		Les nombres négatifs doivent être gérés

	Params :
		- n : L'entier à convertir

	Ret :
		- La chaine de caractères représentant l'entier
		- NULL si l'allocation échoue
*/

#include "libft.h"

static int	count_digit(long n);

char	*ft_itoa(int n)
{
	int		nbr_digit;
	char	*str;
	long	nbr;
	int		i;

	nbr = n;
	nbr_digit = count_digit(nbr);
	str = malloc(sizeof(char) * (nbr_digit + 1));
	if (!str)
		return (NULL);
	str[0] = '0';
	if (nbr < 0)
		nbr = -nbr;
	i = nbr_digit - 1;
	while (nbr != 0)
	{
		str[i] = 48 + nbr % 10;
		nbr = nbr / 10;
		i--;
	}
	if (n < 0)
		str[0] = '-';
	str[nbr_digit] = '\0';
	return (str);
}

static int	count_digit(long n)
{
	int	digits;

	digits = 0;
	if (n < 0)
	{
		digits++;
		n *= -1;
	}
	if (n == 0)
		digits++;
	while (n != 0)
	{
		n = n / 10;
		digits++;
	}
	return (digits);
}
