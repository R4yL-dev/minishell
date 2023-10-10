/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:18:02 by mflury            #+#    #+#             */
/*   Updated: 2023/10/10 23:33:32 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	builtin_pwd(char **argv, t_ctx *ctx)
{
	(void)argv;
	int	pos;

	pos = grpvar_has(ctx->grpvar, GRPVAR_GLOBAL, "PWD");
	if (pos == -1)
		return (1);
	printf("%s\n", ctx->grpvar->global->array[pos]->value);
	return (0);
}
