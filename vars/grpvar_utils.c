/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grpvar_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:52:24 by lray              #+#    #+#             */
/*   Updated: 2023/10/31 20:52:46 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
