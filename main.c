/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 19:08:50 by lray              #+#    #+#             */
/*   Updated: 2023/10/08 13:55:43 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	(void)		argc;
	(void)		argv;
	t_ctx		*ctx;

	ctx = NULL;
	ctx = ctx_init(ctx, envp);
	set_signals(NULL);
	grpvar_show(ctx->grpvar);
	printf("\n");
	while (1)
	{
		ctx_free_line(ctx);
		ctx->input = prompt_get();
		if (ctx->input == NULL)
		{
			clear_history();
			ctx_free(ctx);
			printf("exit\n");
			exit (1);
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

