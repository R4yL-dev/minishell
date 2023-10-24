/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 19:08:50 by lray              #+#    #+#             */
/*   Updated: 2023/10/24 16:34:16 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_in_heredoc = 0;

int	main(int argc, char **argv, char **envp)
{
	(void)				argc;
	(void)				argv;
	t_ctx				*ctx;

	ctx = NULL;
	ctx = ctx_init(ctx, envp);
	while (1)
	{
		ctx_free_line(ctx);
		ctx->input = prompt_get();
		if (ctx->input == NULL)
			builtin_exit(NULL, ctx);
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

