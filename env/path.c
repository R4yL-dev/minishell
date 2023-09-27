/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 21:46:07 by mflury            #+#    #+#             */
/*   Updated: 2023/08/17 03:25:21 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**get_path(t_grpvar *grpvar)
{
	char	**paths;
	size_t	pos;

	pos = grpvar_has(grpvar, GRPVAR_GLOBAL, "PATH");
	if ((int)pos == -1)
		return (NULL);
	paths = ft_split(grpvar->global->array[pos]->value, ':');
	if (paths == NULL)
	{
		ft_puterror("Split error");
		return (NULL);
	}
	return (paths);
}
