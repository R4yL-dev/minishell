/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:49:48 by lray              #+#    #+#             */
/*   Updated: 2023/03/01 15:45:47 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H

# include <stdlib.h>

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}	t_stack;

void	ft_stkpush(t_stack **stack, int data);
int		ft_stkpop(t_stack **stack);
t_stack	*ft_stknew(int data);
int		ft_stkisempty(t_stack *stack);
int		ft_stkpeek(t_stack *stack);
void	ft_stkclear(t_stack **stack);
int		ft_stksize(t_stack *stack);

void	mv_swap(t_stack **stack);

void	db_show_stack(t_stack **stack);

#endif
