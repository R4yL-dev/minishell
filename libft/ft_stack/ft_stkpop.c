/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:58:13 by lray              #+#    #+#             */
/*   Updated: 2023/02/20 22:58:33 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

int	ft_stkpop(t_stack **stack)
{
	t_stack	*tmp;
	int		resp;

	if (ft_stkisempty(*stack))
		return (0);
	tmp = *stack;
	*stack = (*stack)->next;
	resp = tmp->data;
	free(tmp);
	return (resp);
}
