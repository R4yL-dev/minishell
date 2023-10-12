/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   showctx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:28:36 by lray              #+#    #+#             */
/*   Updated: 2023/10/11 14:29:52 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	builtin_showctx(char **argv, t_ctx *ctx)
{
	(void)	argv;

	ctx_show(ctx);
	return (1);
}