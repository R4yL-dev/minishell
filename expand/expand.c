/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:19:55 by lray              #+#    #+#             */
/*   Updated: 2023/09/28 16:18:11 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	replace_var(t_dyntree *root, t_grpvar *grpvar);
static int	is_var(t_dyntree *root);
static int	valide_tree(t_dyntree *root);

t_dyntree	*expand(t_dyntree *root, t_grpvar *grpvar)
{
	if (!replace_var(root, grpvar))
		return (NULL);
	if (!valide_tree(root))
	{
		return (NULL);
	}
	return (root);
}

static int	replace_var(t_dyntree *root, t_grpvar *grpvar)
{
	(void)	grpvar;
	size_t	i;
	size_t	pos;

	if (!root || !grpvar)
		return (0);

	if (is_var(root))
	{
		pos = grpvar_has(grpvar, GRPVAR_GLOBAL, root->value + 1);
		if (ft_strlen(root->value) == 1)
		{
			free(root->value);
			root->value = ft_strdup("$");
		}
		else if ((int)pos < 0)
		{
			free(root->value);
			root->value = ft_strdup("");
		}
		else
		{
			free(root->value);
			root->value = ft_strdup(grpvar->global->array[pos]->value);
		}
	}
	i = 0;
	while (i < root->numChildren)
	{
		if (is_var(root->children[i]))
		{
			pos = grpvar_has(grpvar, GRPVAR_GLOBAL, root->children[i]->value + 1);
			if (ft_strlen(root->children[i]->value) == 1)
			{
				free(root->children[i]->value);
				root->children[i]->value = ft_strdup("$");
			}
			else if ((int)pos < 0)
			{
				free(root->children[i]->value);
				root->children[i]->value = ft_strdup("");
			}
			else
			{
				free(root->children[i]->value);
				root->children[i]->value = ft_strdup(grpvar->global->array[pos]->value);
			}
		}
		replace_var(root->children[i++], grpvar);
	}
	return (1);
}

static int	is_var(t_dyntree *root)
{
	if (root->value[0] == '$')
		return (1);
	return (0);
}

static int	valide_tree(t_dyntree *root)
{
	size_t	i;

	if (!root)
		return (0);
	if (root->type == TK_FILE)
	{
		if (root->value[0] == '\0')
		{
			ft_puterror("ambiguous redirect");
			return (0);
		}
	}
	if (root->type == TK_COMMAND)
	{
		if (root->value[0] == '\0')
			return (0);
	}
	i = 0;
	while (i < root->numChildren)
	{
		if (!valide_tree(root->children[i++]))
			return (0);
	}
	return (1);
}
