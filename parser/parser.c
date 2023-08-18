/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:29:53 by lray              #+#    #+#             */
/*   Updated: 2023/08/18 16:16:07 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static t_dyntree	*exctract_root(t_dyntklist *tklist);
static int			has_token_type(t_dyntklist *tklist, int token_type);

t_dyntree	*parser(t_dyntklist *tklist)
{
	t_dyntree	*root;
	int			i;
	int			num_children;

	root = NULL;
	root = exctract_root(tklist);
	num_children = 0;
	i = 0;
	while (i < (int)tklist->size)
	{
		dyntree_add(root, dyntree_new(tklist->array[i]->type, tklist->array[i]->value));
		if (tklist->array[i]->type == TK_REDIRECTION)
		{
			i++;
			if (tklist->array[i] != NULL)
			{
				num_children = (int)root->numChildren - 1;
				dyntree_add(root->children[num_children], dyntree_new(tklist->array[i]->type, tklist->array[i]->value));
				i++;
			}
			else
			{
				ft_puterror("Error when building tree\n");
			}
		}
		else
		{
			i++;
		}
	}
	return (root);
}

static t_dyntree	*exctract_root(t_dyntklist *tklist)
{
	t_dyntree	*root;
	int			i;

	root = NULL;
	i =  0;
	if (has_token_type(tklist, TK_COMMAND))
	{
		while (tklist->array[i]->type != TK_COMMAND)
			i++;
		root = dyntree_new(tklist->array[i]->type, tklist->array[i]->value);
		dyntklist_delone(tklist, i);
	}
	else if (has_token_type(tklist, TK_REDIRECTION))
	{
		while (tklist->array[i]->type != TK_REDIRECTION)
			i++;
		root = dyntree_new(tklist->array[i]->type, tklist->array[i]->value);
		dyntklist_delone(tklist, i);
	}
	return (root);
}

static int	has_token_type(t_dyntklist *tklist, int token_type)
{
	int	i;

	if (tklist == NULL || tklist->array == NULL || token_type < 0)
		return (0);
	i = 0;
	while (tklist->array[i])
	{
		if (tklist->array[i]->type == token_type)
			return (1);
		i++;
	}
	return (0);
}
