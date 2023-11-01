/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 22:19:41 by lray              #+#    #+#             */
/*   Updated: 2023/11/01 16:27:51 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static pid_t	*make_pids(pid_t *pids, int num_pids);
static void		wait_all(pid_t *pids, int num_cmd, t_ctx *ctx);

int	exec(t_ctx *ctx)
{
	int		**pipes_list;
	pid_t	*pids;
	int		res;

	pids = NULL;
	if (ctx->tree->num_children > 0)
		pids = make_pids(pids, (int)ctx->tree->num_children);
	else if (ctx->tree->num_children == 0)
		pids = make_pids(pids, 1);
	if (ctx->tree->type == TK_PIPE)
	{
		pipes_list = pipes_list_create((int)ctx->tree->num_children - 1);
		exec_piped_cmd(ctx, pipes_list, pids);
		pipes_list_free(pipes_list, (int)ctx->tree->num_children -1);
	}
	else
		res = exec_cmd(ctx, pids);
	if (res == 0)
		return (0);
	if (ctx->tree->num_children > 0)
		wait_all(pids, ctx->tree->num_children, ctx);
	else if (ctx->tree->num_children == 0)
		wait_all(pids, 1, ctx);
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

static void	wait_all(pid_t *pids, int num_cmd, t_ctx *ctx)
{
	int	i;
	int	status;

	status = -1;
	i = 0;
	while (i < num_cmd)
	{
		if (pids[i] != -1)
		{
			waitpid(pids[i], &status, 0);
			if (WIFEXITED(status))
				ctx->ret_code = WEXITSTATUS(status);
			else
				ctx->ret_code = 0;
		}
		++i;
	}
}
