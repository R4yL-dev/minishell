/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:13:11 by lray              #+#    #+#             */
/*   Updated: 2023/02/19 18:57:18 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	process_format(va_list args, const char flag);

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%' && *(str + 1) == '\0')
		{
			ft_printf("[!]Error - %% is not a valid flag.\n");
			return (0);
		}
		if (*str != '%')
			len += ft_putchar(*str);
		else
			len += process_format(args, *(str++ + 1));
		str++;
	}
	va_end(args);
	return (len);
}

static int	process_format(va_list args, const char flag)
{
	int	len;

	len = 0;
	if (flag == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (flag == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (flag == 'p')
		len += ft_putptr(va_arg(args, uintptr_t));
	else if (flag == 'd' || flag == 'i')
		len += ft_put10(va_arg(args, int));
	else if (flag == 'u')
		len += ft_putu10(va_arg(args, unsigned int));
	else if (flag == 'x')
		len += ft_put16(va_arg(args, unsigned int), HEX_LOW);
	else if (flag == 'X')
		len += ft_put16(va_arg(args, unsigned int), HEX_UP);
	else if (flag == '%')
		len += ft_putchar('%');
	else
	{
		ft_printf("[!]Error - %%%c is not a valid flag.\n", flag);
		len = 0;
	}
	return (len);
}

int	ft_putchar(const char c)
{
	write(1, &c, 1);
	return (1);
}
