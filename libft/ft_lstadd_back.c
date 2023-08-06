/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:23:15 by lray              #+#    #+#             */
/*   Updated: 2022/11/03 19:41:57 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Desc :
		Ajoute l'élément new à la fin de la liste.

	Params :
		- lst : L'adresse du pointeur vers le premier élément de la liste.
		- new : L'adresse du pointeur vers l'élément à rajouter à la liste.

	Ret :
		Aucun
*/

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*el;

	el = ft_lstlast(*lst);
	if (!el)
		*lst = new;
	else
		el->next = new;
}
