/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 23:59:21 by mflury            #+#    #+#             */
/*   Updated: 2023/10/14 23:50:41 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	builtin_env(char **argv, t_ctx *ctx)
{
	char	*tmp;
	char	*res;

	tmp = NULL;
	res = NULL;
	if (argv[1])
	{
		tmp = ft_strjoin("env: '", argv[1]);
		res = ft_strjoin(tmp, "': Permission denied\n");
		ft_putstr_fd(res, 2);
		free(tmp);
		free(res);
		return (1);
	}
	if (!ctx->grpvar->global)
		return (1);
	lstvar_show(ctx->grpvar->global);
	return (0);
}
