/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:52:58 by lray              #+#    #+#             */
/*   Updated: 2023/10/29 00:25:12 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	exec_cmd(t_ctx *ctx, pid_t *pids)
{
	int		in_out[2];

	in_out[0] = -1;
	in_out[1] = -1;
	ctx->env = make_env(ctx, ctx->tree, in_out);
	if (ctx->env == NULL)
	{
		free(pids);
		return (0);
	}
	exec_env(ctx, &pids[0], NULL, 0);
	ctx->env = env_free(ctx->env);
	return (1);
}
