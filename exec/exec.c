/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 22:19:41 by lray              #+#    #+#             */
/*   Updated: 2023/10/29 00:25:31 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static pid_t	*make_pids(pid_t *pids, int num_pids);
static void		wait_all(pid_t *pids, int num_cmd);

int	exec(t_ctx *ctx)
{
	int		**pipes_list;
	pid_t	*pids;

	pipes_list = NULL;
	pids = NULL;
	if (ctx->tree->numChildren > 0)
		pids = make_pids(pids, (int)ctx->tree->numChildren);
	else if (ctx->tree->numChildren == 0)
		pids = make_pids(pids, 1);
	if (ctx->tree->type == TK_PIPE)
	{
		pipes_list = pipes_list_create((int)ctx->tree->numChildren - 1);
		exec_piped_cmd(ctx, pipes_list, pids);
		pipes_list_free(pipes_list, (int)ctx->tree->numChildren -1);
	}
	else
		exec_cmd(ctx, pids);
	if (ctx->tree->numChildren > 0)
		wait_all(pids, ctx->tree->numChildren);
	else if (ctx->tree->numChildren == 0)
		wait_all(pids, 1);
	free(pids);
	return (1);
}

static pid_t	*make_pids(pid_t *pids, int num_pids)
{
	int	i;

	i = 0;
	if (!pids)
	{
		pids = malloc(sizeof(pid_t *) * num_pids);
		if (!pids)
		{
			ft_puterror("Malloc failed");
			return (NULL);
		}
		while (i < num_pids)
		{
			pids[i] = -1;
			++i;
		}
	}
	return (pids);
}

static void	wait_all(pid_t *pids, int num_cmd)
{
	int	i;

	i = 0;
	while (i < num_cmd)
	{
		waitpid(pids[i], NULL, 0);
		++i;
	}
}
