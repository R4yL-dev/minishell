/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 23:59:21 by mflury            #+#    #+#             */
/*   Updated: 2023/11/01 20:33:16 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	builtin_env(char **argv, t_ctx *ctx)
{
	char	*tmp;
	char	*res;
	int		i;

	i = 0;
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
	while (i < (int)ctx->grpvar->global->num_elements)
	{
		if (ctx->grpvar->global->array[i]->value)
			printf("%s=%s\n", ctx->grpvar->global->array[i]->name, ctx->grpvar->global->array[i]->value);
		i++;
	}
	return (0);
}
