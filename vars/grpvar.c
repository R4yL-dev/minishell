/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grpvar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 19:02:28 by lray              #+#    #+#             */
/*   Updated: 2023/10/26 11:11:56 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


t_grpvar	*grpvar_init(char **envp)
{
	t_grpvar	*new;

	new = malloc(sizeof(t_lstvar *) * 2);
	if (!new)
	{
		ft_puterror("Malloc failed");
		return (NULL);
	}
	new->global = lstvar_init(envp);
	new->local = lstvar_init(NULL);
	return (new);
}

int	grpvar_add(t_grpvar *grpvar, int lstvar, char *name, char *value)
{
	if (!grpvar || !name)
	{
		ft_puterror("grpvar, name and value cannot be NULL");
		return (0);
	}
	if (lstvar != GRPVAR_GLOBAL && lstvar != GRPVAR_LOCAL)
	{
		ft_puterror("lstvar unknown");
		return (0);
	}
	if (lstvar == GRPVAR_GLOBAL)
	{
		if (value == NULL)
		{
			if (!lstvar_add(grpvar->global, var_new(name, "")))
			{
				ft_puterror("Error adding variable to grpvar->global");
				return (0);
			}
		}
		else
		{
			if (!lstvar_add(grpvar->global, var_new(name, value)))
			{
				ft_puterror("Error adding variable to grpvar->global");
				return (0);
			}
		}
	}
	else
	{
		if (!lstvar_add(grpvar->local, var_new(name, value)))
		{
			ft_puterror("Error adding variable to grpvar->global");
			return (0);
		}
	}
	return (1);
}

void	grpvar_show(t_grpvar *grpvar)
{
	if (grpvar)
	{
		printf("= GRPVAR SHOW =\n");
		if (grpvar->global)
		{
			printf("== GLOBAL ==\n");
			lstvar_show(grpvar->global);
			printf("Number of global variable : %ld\n", grpvar->global->num_elements);
		}
		if (grpvar->local)
		{
			printf("== LOCAL ==\n");
			lstvar_show(grpvar->local);
			printf("Number of local variable : %ld\n", grpvar->local->num_elements);
		}
	}
}

size_t	grpvar_has(t_grpvar *grpvar, int lstvar, char *name)
{
	size_t	res;

	if (!grpvar || !name)
	{
		ft_puterror("grpvar and name cannot be NULL");
		return (-1);
	}
	if (lstvar != GRPVAR_GLOBAL && lstvar != GRPVAR_LOCAL)
	{
		ft_puterror("lstvar unknown");
		return (-1);
	}
	if (lstvar == GRPVAR_GLOBAL)
		res = lstvar_has(grpvar->global, name);
	else
		res = lstvar_has(grpvar->local, name);
	return (res);
}

int	grpvar_remove(t_grpvar *grpvar, int lstvar, size_t index)
{
	if (!grpvar)
	{
		ft_puterror("grpvar cannot be NULL");
		return (0);
	}
	if (lstvar != GRPVAR_GLOBAL && lstvar != GRPVAR_LOCAL)
	{
		ft_puterror("lstvar unknown");
		return (-1);
	}
	if (lstvar == GRPVAR_GLOBAL)
		return (lstvar_remove(grpvar->global, index));
	else
		return (lstvar_remove(grpvar->local, index));
}

void	grpvar_free(t_grpvar *grpvar)
{
	if (grpvar)
	{
		if (grpvar->global)
		{
			lstvar_free(grpvar->global);
			grpvar->global = NULL;
		}
		if (grpvar->local)
		{
			lstvar_free(grpvar->local);
			grpvar->local = NULL;
		}
		free(grpvar);
		grpvar = NULL;
	}
}

