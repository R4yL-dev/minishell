/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 02:30:09 by mflury            #+#    #+#             */
/*   Updated: 2023/10/13 18:04:02 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	builtin_cd(char **argv, t_ctx *ctx)
{
	char	*buf;
	int		pos;
	
	buf = NULL;
	pos = grpvar_has(ctx->grpvar, GRPVAR_GLOBAL, "HOME");
	if (pos == -1)
		printf ("cant find home\n");
	if (!argv[1] || (argv[1][0] == '~' && argv[1][1] == '\0'))
	{
		if (chdir(ctx->grpvar->global->array[pos]->value) == -1)
			printf("cd failed\n");
		buf = getcwd(NULL, 0);
		grpvar_add(ctx->grpvar, GRPVAR_GLOBAL, "PWD", buf);
	}
	else
	{
		if (chdir(argv[1]) == -1)
			printf("cd failed\n");
		buf = getcwd(NULL, 0);
		grpvar_add(ctx->grpvar, GRPVAR_GLOBAL, "PWD", buf);
	}
	free(buf);
	return (0);
}
