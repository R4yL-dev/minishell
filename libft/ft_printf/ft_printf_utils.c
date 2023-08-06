/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:20:02 by lray              #+#    #+#             */
/*   Updated: 2023/04/06 11:54:18 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const char *str)
{
	int	len;

	len = 0;
	if (str == NULL)
		len = ft_putstr("(null)");
	else
	{
		while (*str)
		{
			len += ft_putchar(*str);
			str++;
		}
	}
	return (len);
}

int	ft_putptr(uintptr_t addr)
{
	int	len;

	len = 0;
	len += ft_putstr("0x");
	len += ft_put16(addr, HEX_LOW);
	return (len);
}

int	ft_put10(int nbr)
{
	int	len;

	len = 0;
	if (nbr == -2147483648)
		len += ft_putstr("-2147483648");
	else if (nbr < 0)
	{
		len += ft_putchar('-');
		nbr = nbr * -1;
		len += ft_put10(nbr);
	}
	else
	{
		if (nbr >= 10)
		{
			len += ft_put10(nbr / 10);
			len += ft_put10(nbr % 10);
		}
		else
			len += ft_putchar(nbr + 48);
	}
	return (len);
}

int	ft_putu10(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr >= 10)
	{
		len += ft_putu10(nbr / 10);
		len += ft_putu10(nbr % 10);
	}
	else
		len += ft_putchar(nbr + 48);
	return (len);
}

int	ft_put16(uintptr_t nbr, char *set)
{
	int	len;

	len = 0;
	if (nbr >= 16)
	{
		len += ft_put16(nbr / 16, set);
		len += ft_put16(nbr % 16, set);
	}
	else
		len += ft_putchar(set[nbr]);
	return (len);
}
