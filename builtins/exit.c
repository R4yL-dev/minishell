/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:12:24 by mflury            #+#    #+#             */
/*   Updated: 2023/10/10 20:59:52 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// note that "1" in exit() should be replaced by the global
// error code modulo 256 when we implement it.

int	builtin_exit(char **argv, t_ctx *ctx)
{
	(void)argv;

	clear_history();
	ctx_free(ctx);
	printf("exit\n");
	exit (1 % 256);
}
