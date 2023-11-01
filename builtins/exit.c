/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:12:24 by mflury            #+#    #+#             */
/*   Updated: 2023/11/01 16:44:13 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	builtin_exit(char **argv, t_ctx *ctx)
{
	int	code;

	(void) argv;
	printf("exit\n");
	if (!argv || !argv[1])
		code = ctx->ret_code;
	else if (argv[2] != NULL)
	{
		ft_puterror("exit: too many arguments");
		return (1);
	}
	else
		code = ft_atoi(argv[1]);
	clear_history();
	ctx_free(ctx);
	exit(code);
}
