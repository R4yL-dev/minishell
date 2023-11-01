/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_piped_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:51:16 by lray              #+#    #+#             */
/*   Updated: 2023/10/30 13:43:12 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	get_env(t_ctx *ctx, int **pl, size_t i);

int	exec_piped_cmd(t_ctx *ctx, int **pl, pid_t *pids)
{
	size_t	i;

	i = 0;
	while (i < ctx->tree->num_children)
	{
		if (!get_env(ctx, pl, i))
			return (0);
		if (ctx->env != NULL)
		{
			exec_env(ctx, &pids[i], pl, (int)ctx->tree->num_children - 1);
			ctx->env = env_free(ctx->env);
		}
		++i;
	}
	return (1);
}

static int	get_env(t_ctx *ctx, int **pl, size_t i)
{
	int	in_out[2];

	in_out[0] = -1;
	in_out[1] = -1;
	if (i == 0)
		in_out[1] = pl[i][1];
	else if ((int)i == (int)ctx->tree->num_children - 1)
		in_out[0] = pl[(int)i - 1][0];
	else
	{
		in_out[0] = pl[(int)i - 1][0];
		in_out[1] = pl[i][1];
	}
	ctx->env = make_env(ctx, ctx->tree->children[i], in_out);
	if (!ctx->env)
		return (0);
	return (1);
}
