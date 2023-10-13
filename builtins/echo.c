/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:23:16 by mflury            #+#    #+#             */
/*   Updated: 2023/10/13 22:11:36 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	builtin_echo(char **argv, t_ctx *ctx)
{
	int i;

	(void)ctx;
	i = 1;
	if (!argv[1])
		printf("\n");
	else if (ft_strncmp(argv[1], "-n\0", 3) != 0 || argv[1] == NULL)
	{
		while (argv[i])
		{
			printf("%s", argv[i++]);
			if (argv[i])
				printf(" ");
		}
		printf("\n");
	}
	else
	{
		i = 2;
		while (argv[i])
			printf("%s", argv[i++]);
	}
	return (0);
}
