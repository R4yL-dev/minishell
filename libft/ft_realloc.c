/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:10:23 by lray              #+#    #+#             */
/*   Updated: 2023/08/11 15:18:26 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t original_length, size_t new_length)
{
	void	*ptr_new;

	if (new_length == 0)
	{
		free(ptr);
		return (NULL);
	}
	else if (ptr == NULL)
	{
		return (malloc(new_length));
	}
	else if (new_length <= original_length)
	{
		return (ptr);
	}
	else
	{
		ptr_new = malloc(new_length);
		if (ptr_new)
		{
			ft_memcpy(ptr_new, ptr, original_length);
			free(ptr);
		}
		return (ptr_new);
	}
}
