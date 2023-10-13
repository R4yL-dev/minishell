/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 02:30:09 by mflury            #+#    #+#             */
/*   Updated: 2023/10/13 06:33:47 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// le changement de dir marche, pas la valeur de pwd apres:
// pwd before works.
// before/after via getcwd() works.
// pwd after doesnt work... FML!
//
// MiniShrek$ pwd
// /mnt/c/Users/FizzY WizzY/Desktop/Code/42_projects/42_30_minishell/EL_MINISHREK
// MiniShrek$ cd
// before cd: /mnt/c/Users/FizzY WizzY/Desktop/Code/42_projects/42_30_minishell/EL_MINISHREK
// after cd: /home/fizzywizzy
// MiniShrek$ pwd
// ���@"
// MiniShrek$ 

int	builtin_cd(char **argv, t_ctx *ctx)
{
	char	*path_home;
	char	buf[256];
	int		pos;
	getcwd(buf, sizeof(buf));
	pos = 0;
	while (ft_strncmp(ctx->grpvar->global->array[pos]->name, "HOME", 4) != 0)
		pos++;
	path_home = ctx->grpvar->global->array[pos]->value;
	pos = 0;
	while (ft_strncmp(ctx->grpvar->global->array[pos]->name, "PWD", 3) != 0)
		pos++;
	if (!argv[1])
	{
		printf("before cd: %s\n", buf);
		if (chdir(path_home) == -1)
			printf("cd failed\n");
		getcwd(buf, 256);
		printf("after cd: %s\n", buf);
		ctx->grpvar->global->array[pos]->value = buf;
	}
	else
	{
		printf("before cd: %s\n", buf);
		if (chdir(argv[1]) == -1)
			printf("cd failed\n");
		getcwd(buf, 256);
		printf("after cd: %s\n", buf);
		ctx->grpvar->global->array[pos]->value = buf;
	}
	return (0);
}
