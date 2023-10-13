/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 23:59:21 by mflury            #+#    #+#             */
/*   Updated: 2023/10/14 01:03:03 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	builtin_env(char **argv, t_ctx *ctx)
{
	if (argv[1])
	{
		printf("env: '%s': Permission denied\n", argv[1]);
		return (1);
	}
	if (!ctx->grpvar->global)
		return (1);
	lstvar_show(ctx->grpvar->global);
	return (0);
}
