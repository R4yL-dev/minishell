/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_an_executable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 23:45:33 by lray              #+#    #+#             */
/*   Updated: 2023/11/01 15:11:13 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_an_executable(char *path)
{
	struct stat	sb;

	if (stat(path, &sb) == 0)
	{
		if (S_ISDIR(sb.st_mode))
			return (0);
	}
	if (access(path, (F_OK | X_OK)) == -1)
		return (0);
	return (1);
}
