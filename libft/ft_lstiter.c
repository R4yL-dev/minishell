/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:56:54 by lray              #+#    #+#             */
/*   Updated: 2022/11/06 14:08:58 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Desc :
		Itère sur la liste lst et applique la fonction f au contenu
		de chaque élément.

	Params :
		- lst : L'adresse du pointeur vers un élément.
		- f : L'adresse de la fonction à appliquer.

	Ret :
		Aucun
*/

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
