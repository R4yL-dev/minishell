/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:57:48 by lray              #+#    #+#             */
/*   Updated: 2023/04/19 18:31:02 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_stkpush(t_stack **stack, int data)
{
	t_stack	*new_node;

	new_node = ft_stknew(data);
	new_node->next = *stack;
	*stack = new_node;
}
