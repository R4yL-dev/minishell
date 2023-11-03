/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 23:59:21 by mflury            #+#    #+#             */
/*   Updated: 2023/11/02 17:03:28 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	process_print(t_var *var);

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
		process_print(ctx->grpvar->global->array[i]);
		i++;
	}
	return (0);
}

static void	process_print(t_var *var)
{
	if (var->value)
		printf("%s=%s\n", var->name, var->value);
}
