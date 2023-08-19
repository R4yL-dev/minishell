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

char	**get_path(void)
{
	char	*path;
	char	**paths;

	path = NULL;
	path = getenv("PATH");
	if (path == NULL)
	{
		ft_puterror("Get_env error, $PATH does't exist");
		return (NULL);
	}
	path = ft_strtrim(path, "PATH=");
	paths = ft_split(path, ':');
	if (paths == NULL)
	{
		ft_puterror("Split error");
		return (NULL);
	}
	free(path);
	return (paths);
}
