/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:45:33 by lray              #+#    #+#             */
/*   Updated: 2022/11/03 19:29:16 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Desc :
		Ajoute l'élément new au début de la liste.

	Params :
		- lst : L'adresse du pointeur ver le premier élément de la liste.
		- new : L'adresse du pointeur vers l'élément à rajouter à la liste.

	Ret :
		Auncun
*/

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
