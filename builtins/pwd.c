/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:18:02 by mflury            #+#    #+#             */
/*   Updated: 2023/10/31 20:36:19 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	builtin_pwd(char **argv, t_ctx *ctx)
{
	int	pos;

	(void) argv;
	pos = grpvar_has(ctx->grpvar, GRPVAR_GLOBAL, "PWD");
	if (pos == -1)
		return (1);
	printf("%s\n", ctx->grpvar->global->array[pos]->value);
	return (0);
}
