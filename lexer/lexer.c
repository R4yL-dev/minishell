/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 23:26:56 by lray              #+#    #+#             */
/*   Updated: 2023/10/30 12:32:56 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	skip_space(char *input, int *i);
static int	process_word(t_ctx *ctx, int *i, int *in_cmd);
static int	process_redirect(t_ctx *ctx, int *i, int *in_cmd);
static int	process_cmd_or_arg(t_ctx *ctx, int *i, int *in_cmd);

int	lexer(t_ctx *ctx)
{
	int	i;
	int	in_cmd;

	in_cmd = 0;
	i = 0;
	ctx->tklist = dyntklist_init(ctx->tklist);
	if (ctx->tklist == NULL)
		return (0);
	while (ctx->input[i] != '\0')
	{
		skip_space(ctx->input, &i);
		if (ctx->input[i] == '\0')
			break ;
		if (process_word(ctx, &i, &in_cmd) == 0)
			return (0);
	}
	if (ctx->tklist->size == 0)
		return (0);
	return (1);
}

static void	skip_space(char *input, int *i)
{
	while (input[*i] != '\0' && input[*i] == ' ')
		(*i)++;
}

static int	process_word(t_ctx *ctx, int *i, int *in_cmd)
{
	if (is_redirect(ctx->input[*i]))
	{
		if (process_redirect(ctx, i, in_cmd) == 0)
			return (0);
	}
	else
	{
		if (process_cmd_or_arg(ctx, i, in_cmd) == 0)
			return (0);
	}
	return (1);
}

static int	process_redirect(t_ctx *ctx, int *i, int *in_cmd)
{
	if (is_pipe(ctx->input[*i]))
	{
		dyntklist_add(ctx->tklist, TK_PIPE, "|");
		*in_cmd = 0;
		(*i)++;
	}
	else
	{
		if (add_redirect(ctx, ctx->tklist, i) == 0)
			return (0);
		skip_space(ctx->input, i);
		if (add_to_tklist(ctx->input, i, ctx->tklist, TK_FILE) == 0)
			return (0);
	}
	return (1);
}

static int	process_cmd_or_arg(t_ctx *ctx, int *i, int *in_cmd)
{
	if (*in_cmd == 0)
	{
		if (add_to_tklist(ctx->input, i, ctx->tklist, TK_COMMAND) == 0)
			return (0);
		*in_cmd = 1;
	}
	else
	{
		if (add_to_tklist(ctx->input, i, ctx->tklist, TK_ARGUMENT) == 0)
			return (0);
	}
	return (1);
}
