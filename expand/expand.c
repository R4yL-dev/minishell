/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:19:55 by lray              #+#    #+#             */
/*   Updated: 2023/10/07 18:44:15 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	valide_tree(t_dyntree *root);

t_dyntree	*expand(t_dyntree *root, t_grpvar *grpvar)
{
	if (!root || !grpvar)
		return (NULL);
	if (!replace_var(root, grpvar))
		return (NULL);
	if (!valide_tree(root))
		return (NULL);
	replace_builtins(root);
	return (root);
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
	else if (root->type == TK_PIPE)
	{
		if (root->numChildren < 2)
		{
			ft_puterror("ambiguous redirect");
			return (0);
		}
	}
	else if (root->type == TK_COMMAND)
	{
		if (root->value[0] == '\0')
			return (0);
	}
	else if (root->type == TK_REDIRECTION)
	{
		if (root->numChildren < 1 || root->children[0]->type != TK_FILE)
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
