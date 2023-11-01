/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cmd_to_root.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:00:07 by lray              #+#    #+#             */
/*   Updated: 2023/10/30 13:37:53 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static t_dyntree	*process_split(t_dyntree *root, t_dyntklist **res);
static t_dyntree	*process_add(t_dyntree *r, t_dyntklist **res, int i, int p);

t_dyntree	*add_cmd_to_root(t_dyntklist *tklist, t_dyntree *root)
{
	t_dyntklist	**res;

	res = dyntklist_split(tklist);
	root = process_split(root, res);
	dyntklist_split_free(res);
	return (root);
}

static t_dyntree	*process_split(t_dyntree *root, t_dyntklist **res)
{
	int			i;
	int			pos;

	i = 0;
	while (res[i])
	{
		pos = has_token_type(res[i], TK_COMMAND);
		if (pos != -1)
		{
			process_add(root, res, i, pos);
			i++;
			continue ;
		}
		pos = has_token_type(res[i], TK_REDIRECTION);
		if (pos != -1)
		{
			process_add(root, res, i, pos);
			i++;
			continue ;
		}
		else
			return (NULL);
	}
	return (root);
}

static t_dyntree	*process_add(t_dyntree *r, t_dyntklist **res, int i, int p)
{
	dyntree_add(r, \
	dyntree_new(res[i]->array[p]->type, res[i]->array[p]->value));
	return (r);
}
