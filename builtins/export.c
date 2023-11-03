/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 01:51:07 by mflury            #+#    #+#             */
/*   Updated: 2023/11/02 23:13:46 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*build_var_value(char **tab)
{
	int		i;
	char	*tmp1;
	char	*tmp2;

	i = 1;
	tmp1 = ft_strjoin(tab[i], "");
	i++;
	while (i < tablen(tab))
	{
		if (tab[i])
		{
			tmp2 = ft_strjoin(tmp1, "=");
			free(tmp1);
			tmp1 = NULL;
			tmp1 = ft_strjoin(tmp2, tab[i]);
			free(tmp2);
			tmp2 = NULL;
		}
		i++;
	}
	return (tmp1);
}

void	add_var_list_two_args(char **argv, char **tab, t_ctx *ctx)
{
	int		i;
	char	*value;

	i = 1;
	if (argv[i][ft_strlen(argv[i]) - 1] == '=')
	{
		value = ft_strjoin(tab[1], "=");
		grpvar_add(ctx->grpvar, GRPVAR_GLOBAL, tab[0], value);
		free(value);
	}
	else
		grpvar_add(ctx->grpvar, GRPVAR_GLOBAL, tab[0], tab[1]);
}

void	add_var_list_bullshit_args(char **argv, char **tab, t_ctx *ctx)
{
	int		i;
	char	*value;
	char	*var_value;

	i = 1;
	var_value = build_var_value(tab);
	if (argv[i][ft_strlen(argv[i]) - 1] == '=')
	{
		value = ft_strjoin(var_value, "=");
		grpvar_add(ctx->grpvar, GRPVAR_GLOBAL, tab[0], value);
		free(value);
	}
	else
		grpvar_add(ctx->grpvar, GRPVAR_GLOBAL, tab[0], var_value);
	free(var_value);
}

void	add_var_list(char **argv, t_ctx *ctx)
{
	char	**tab;
	int		i;
	int		j;

	i = 1;
	tab = NULL;
	while (argv[i])
	{
		tab = ft_split(argv[i], '=');
		if (tablen(tab) == 1)
			grpvar_add(ctx->grpvar, GRPVAR_GLOBAL, tab[0], NULL);
		else if (tablen(tab) == 2)
			add_var_list_two_args(argv, tab, ctx);
		else
			add_var_list_bullshit_args(argv, tab, ctx);
		j = 0;
		while (tab[j])
		{
			free(tab[j]);
			j++;
		}
		free(tab);
		i++;
	}
}

int	builtin_export(char **argv, t_ctx *ctx)
{
	char	**sorted_list;
	char	**unsorted_list;

	if (!argv[1])
	{
		unsorted_list = copy_names(ctx->grpvar->global);
		sorted_list = sort_names(unsorted_list, ctx->grpvar->global);
		call_names_alpha(sorted_list, ctx->grpvar->global);
	}
	else
		add_var_list(argv, ctx);
	return (0);
}
