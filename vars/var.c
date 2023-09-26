/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:39:08 by lray              #+#    #+#             */
/*   Updated: 2023/09/26 17:31:21 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_var	*var_new(char *name, char *value)
{
	t_var	*new;

	if (!name || !value)
	{
		ft_puterror("Cannot create var without a name or a value");
		return (NULL);
	}
	new = malloc(sizeof(t_var) * 1);
	if (!new)
	{
		ft_puterror("Malloc failed");
		return (NULL);
	}
	new->name = ft_strdup(name);
	new->value = ft_strdup(value);
	return (new);
}

void	var_show(t_var *var)
{
	if (var)
	{
		printf("var name : ");
		if (var->name)
			printf("%s", var->name);
		else
			printf("(null)");
		printf(" | value : ");
		if (var->value)
			printf("%s", var->value);
		else
			printf("(null)");
	}
	printf("\n");
}

void	var_free(t_var	*var)
{
	if (var)
	{
		free(var->name);
		var->name = NULL;
		free(var->value);
		var->value = NULL;
		free(var);
		var = NULL;
	}
}
