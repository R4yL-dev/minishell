/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:23:16 by mflury            #+#    #+#             */
/*   Updated: 2023/11/01 15:59:09 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	builtin_echo(char **argv, t_ctx *ctx)
{
	int	i;

	(void) ctx;
	if (!argv[1])
		printf("\n");
	else
	{
		if (ft_strncmp(argv[1], "-n", 3) != 0 || argv[1] == NULL)
			i = 1;
		else
			i = 2;
		while (argv[i])
		{
			printf("%s", argv[i++]);
			if (argv[i])
				printf(" ");
		}
		if (ft_strncmp(argv[1], "-n", 3) != 0 || argv[1] == NULL)
			printf("\n");
	}
	return (0);
}
