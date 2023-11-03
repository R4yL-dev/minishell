/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:08:25 by lray              #+#    #+#             */
/*   Updated: 2023/11/01 12:24:15 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	set_home(t_grpvar *grpvar);

int	var_set_init_value(t_ctx *ctx)
{
	grpvar_add(ctx->grpvar, GRPVAR_GLOBAL, "PWD", NULL);
	grpvar_add(ctx->grpvar, GRPVAR_GLOBAL, "OLDPWD", NULL);
	set_home(ctx->grpvar);
	return (1);
}

static void	set_home(t_grpvar *grpvar)
{
	int	pos;

	pos = grpvar_has(grpvar, GRPVAR_GLOBAL, "HOME");
	if (pos == -1 || grpvar->global->array[pos]->value[0] == '\0')
		grpvar_add(grpvar, GRPVAR_GLOBAL, "HOME", "/");
}
