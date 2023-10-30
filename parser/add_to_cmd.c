/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:58:41 by lray              #+#    #+#             */
/*   Updated: 2023/10/30 13:45:46 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	process_tklist(t_dyntree *root, t_dyntklist *tklist, int *i);
static int	process_redirection(t_dyntree *root, t_dyntklist *tklist, int *i);

int	add_to_cmd(t_dyntklist *tklist, t_dyntree *root, int pos)
{
	int			i;

	i = pos;
	if (pos > (int)tklist->size)
		return (-1);
	if (root->type == TK_REDIRECTION)
		++i;
	i = process_tklist(root, tklist, &i);
	return (i);
}

static int	process_tklist(t_dyntree *root, t_dyntklist *tklist, int *i)
{

	while (*i < (int)tklist->size && tklist->array[*i]->type != TK_PIPE)
	{
		if (tklist->array[*i]->type == TK_PIPE)
			return (*i);
		if (tklist->array[*i]->type == TK_COMMAND)
		{
			(*i)++;
			continue ;
		}
		dyntree_add(root, dyntree_new(tklist->array[*i]->type, \
		tklist->array[*i]->value));
		if (tklist->array[*i]->type == TK_REDIRECTION)
		{
			(*i)++;
			if (process_redirection(root, tklist, i) == -1)
				return (-1);
		}
		else
			(*i)++;
	}
	return (*i);
}

static int	process_redirection(t_dyntree *root, t_dyntklist *tklist, int *i)
{
	int			num_children;

	num_children = 0;
	if (tklist->array[*i] != NULL)
	{
		num_children = (int)root->num_children - 1;
		dyntree_add(root->children[num_children], \
		dyntree_new(tklist->array[*i]->type, tklist->array[*i]->value));
		(*i)++;
		return (1);
	}
	else
		return (-1);
}
