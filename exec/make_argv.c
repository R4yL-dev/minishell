/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_argv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:58:19 by lray              #+#    #+#             */
/*   Updated: 2023/10/29 00:25:54 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_dynarrstr	*make_argv(t_dyntree *root)
{
	t_dynarrstr	*res;
	size_t		i_child;

	res = NULL;
	if (root == NULL)
		return (NULL);
	res = dynarrstr_init(res);
	if (res == NULL)
		return (NULL);
	if (!dynarrstr_add(res, root->value))
		return (NULL);
	i_child = 0;
	while (i_child < root->numChildren)
	{
		if (root->children[i_child]->type == TK_ARGUMENT)
		{
			if (!dynarrstr_add(res, root->children[i_child]->value))
				return (NULL);
		}
		++i_child;
	}
	return (res);
}
