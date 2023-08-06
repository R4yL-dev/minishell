/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:43:22 by lray              #+#    #+#             */
/*   Updated: 2023/02/20 23:12:10 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Desc :
		Libère la mémoire de l'élément passé en argument en utilisant la
		fonction del puis avec free.
		La mémoire de next ne doit pas être free.

	Params :
		- lst : L'élément à free.
		- del : L'adresse de la fonction permettant de supprimer le contenu
			de l'élément

	Ret :
		Aucun
*/

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
