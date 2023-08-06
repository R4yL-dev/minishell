/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 18:09:17 by lray              #+#    #+#             */
/*   Updated: 2023/02/20 23:12:05 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Desc :
		 Supprime et libère la mémoire de l'élément passé en paramètre, et de
		 tous les éléments qui suivent, à l'aide de del et de free.
		 Enfin, le pointeur initial doit être mis à NULL.

	Params :
		- lst : L'adresse du pointeur vers un élément.
		- del : L'adresse de la fonction permettant de supprimer le
		contenu d'un élément.

	Ret :
		Aucun
*/

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*el;

	while (*lst)
	{
		el = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = el;
	}
	free(*lst);
	*lst = NULL;
}
