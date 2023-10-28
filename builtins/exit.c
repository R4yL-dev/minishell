/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:12:24 by mflury            #+#    #+#             */
/*   Updated: 2023/10/26 21:17:14 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	builtin_exit(char **argv, t_ctx *ctx)
{
	(void)argv;
	int	code;

	code = ctx->ret_code;
	clear_history();
	ctx_free(ctx);
	printf("exit\n");
	exit(code);
}
