/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 14:10:58 by lray              #+#    #+#             */
/*   Updated: 2023/02/20 23:12:28 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Desc :
		Itère sur la liste lst et applique la fonction d au contenu de
		chaque élément.
		Crée une nouvelle liste résultant des applications successives de f.
		La fonction del est là pour détruire le contenu d'un
		élément si nécessaire.

	Params :
		- lst : L'adresse du pointeur vers un élément.
		- f : L'adresse de la fonction à appliquer.
		- del : L'adresse de la fonction permettant de supprimer
		le contenu d'un élément.

	Ret :
		La nouvelle liste.
		NULL si l'allocation échoue.
*/

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*resp;
	t_list	*el;

	if (!f || !del || !del)
		return (NULL);
	resp = NULL;
	while (lst)
	{
		el = ft_lstnew(f(lst->content));
		if (el == NULL)
		{
			ft_lstclear(&resp, del);
			return (NULL);
		}
		ft_lstadd_back(&resp, el);
		lst = lst->next;
	}
	return (resp);
}
