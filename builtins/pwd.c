/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:18:02 by mflury            #+#    #+#             */
/*   Updated: 2023/10/10 21:58:24 by mflury           ###   ########.fr       */
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
	if (!tmp)
		return (1);
	while (ft_strncmp(tmp->global->array[i]->name, "PWD", 3) != 0)
		i++;
	if (ft_strncmp(tmp->global->array[i]->name, "PWD", 3) == 0)
	{
		printf("%s\n", tmp->global->array[i]->value);
		return (0);
	}
	else
		printf("fuck it doesnt work T_T");
	return (314);
}
