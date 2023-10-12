/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 23:59:21 by mflury            #+#    #+#             */
/*   Updated: 2023/10/13 00:48:17 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	builtin_env(char **argv, t_ctx *ctx)
{
	int	pos;
	(void)argv;

	pos = 0;
	if(!ctx->grpvar->global->array)
		return (1);
	while (pos < (int)ctx->grpvar->global->num_elements)
	{
		printf("%s=%s\n", ctx->grpvar->global->array[pos]->name, ctx->grpvar->global->array[pos]->value);
		pos++;
	}
	return (0);
}
