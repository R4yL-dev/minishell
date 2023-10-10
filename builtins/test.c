/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:57:29 by lray              #+#    #+#             */
/*   Updated: 2023/10/09 20:14:20 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	builtin_test(char **argv, t_ctx *ctx)
{
	(void)	argv;
	(void)	ctx;
	printf("JE SUIS LA BUILTIN TEST !!!\n");
	return (1);
}
