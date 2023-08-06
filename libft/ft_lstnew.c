/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:43:57 by lray              #+#    #+#             */
/*   Updated: 2023/02/20 23:13:11 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Desc :
		Alloue et renvoie un nouvel élément. La variable membre content
		est initialisée à l'aide de la valeur du paramètre content.
		La variable next est initialisée à NULL.

	Params :
		- content : Le contenu du nouvel élément.

	Ret :
		Le nouvel élément.
*/

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*el;

	el = (t_list *)malloc(sizeof(t_list));
	if (!el)
		return (NULL);
	el->content = content;
	el->next = NULL;
	return (el);
}
