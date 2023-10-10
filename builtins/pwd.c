/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:18:02 by mflury            #+#    #+#             */
/*   Updated: 2023/10/10 22:22:07 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	builtin_pwd(char **argv, t_ctx *ctx)
{
	(void)argv;
	int	i;
	t_grpvar *tmp;

	i = 0;
	tmp = ctx->grpvar;
	if (!tmp->global)
		return (1);
	while (ft_strncmp(tmp->global->array[i]->name, "PWD", 3) != 0 && tmp->global->array[i])
		i++;
	if (!tmp->global->array[i])
		return (1);
	printf("%s\n", tmp->global->array[i]->value);
	return (0);
}
