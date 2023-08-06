/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stksize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:56:18 by lray              #+#    #+#             */
/*   Updated: 2023/02/20 22:56:42 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

int	ft_stksize(t_stack *stack)
{
	int	resp;

	resp = 0;
	while (stack)
	{
		resp++;
		stack = stack->next;
	}
	return (resp);
}
