/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 19:08:50 by lray              #+#    #+#             */
/*   Updated: 2023/11/01 12:28:05 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_ctx	*app_init(t_ctx *ctx, char **envp);

int	g_in_heredoc = 0;

int	main(int argc, char **argv, char **envp)
{
	t_ctx	*ctx;

	(void) argc, (void) argv;
	ctx = NULL;
	ctx = app_init(ctx, envp);
	while (1)
	{
		ctx_free_line(ctx);
		ctx->input = prompt_get();
		if (ctx->input == NULL)
		{
			ctx->ret_code = 0;
			builtin_exit(NULL, ctx);
		}
		else if (ctx->input[0] == '\0')
			continue ;
		if (lexer(ctx) == 0)
			continue ;
		if (parser(ctx) == 0)
			continue ;
		if (expand(ctx) == 0)
			continue ;
		exec(ctx);
	}
	return (0);
}

static t_ctx	*app_init(t_ctx *ctx, char **envp)
{
	ctx = ctx_init(ctx, envp);
	return (ctx);
}
