/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:29:53 by lray              #+#    #+#             */
/*   Updated: 2023/09/15 18:35:57 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static t_dyntree	*exctract_root(t_dyntklist *tklist);
static int			has_token_type(t_dyntklist *tklist, int token_type);
static int	add_to_cmd(t_dyntklist *tklist, t_dyntree *root, int pos);
static t_dyntree	*add_cmd_to_root(t_dyntklist *tklist, t_dyntree *root);

t_dyntree	*parser(t_dyntklist *tklist)
{
	t_dyntree	*root;
	size_t		i;
	int			last_pipe;

	root = NULL;
	root = exctract_root(tklist);

	if (root->type == TK_COMMAND || root->type == TK_REDIRECTION)
	{
		add_to_cmd(tklist, root, 0);
	}
	else if (root->type == TK_PIPE)
	{
		add_cmd_to_root(tklist, root);
		i = 0;
		last_pipe = 0;
		while (i < root->numChildren)
		{
			last_pipe = add_to_cmd(tklist, root->children[i], last_pipe) + 1;
			if (last_pipe == -1)
			{
				printf("ERREUR\n");
				break ;
			}
			++i;
		}
	}
	else
	{
		ft_puterror("Unknow root");
		return (NULL);
	}
	return (root);
}

static t_dyntree	*exctract_root(t_dyntklist *tklist)
{
	t_dyntree	*root;
	int			i;

	root = NULL;
	i =  0;
	if (has_token_type(tklist, TK_PIPE))
	{
		while (tklist->array[i]->type != TK_PIPE)
			i++;
		root = dyntree_new(TK_PIPE, "|");
	}
	else if (has_token_type(tklist, TK_COMMAND))
	{
		while (tklist->array[i]->type != TK_COMMAND)
			i++;
		root = dyntree_new(tklist->array[i]->type, tklist->array[i]->value);
	}
	else if (has_token_type(tklist, TK_REDIRECTION))
	{
		while (tklist->array[i]->type != TK_REDIRECTION)
			i++;
		root = dyntree_new(tklist->array[i]->type, tklist->array[i]->value);
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

static int	add_to_cmd(t_dyntklist *tklist, t_dyntree *root, int pos)
{
	int			i;
	int			num_children;

	num_children = 0;
	i = pos;
	if (pos > (int)tklist->size)
		return (-1);
	if (root->type == TK_REDIRECTION)
		++i;
	while (i < (int)tklist->size && tklist->array[i]->type != TK_PIPE)
	{
		if (tklist->array[i]->type == TK_PIPE)
			return (i);
		if (tklist->array[i]->type == TK_COMMAND)
		{
			++i;
			continue ;
		}
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
				return (-1);
			}
		}
		else
		{
			++i;
		}
	}
	return (i);
}

static t_dyntree	*add_cmd_to_root(t_dyntklist *tklist, t_dyntree *root)
{
	size_t	i;

	i = 0;
	while (i < tklist->size)
	{
		if (tklist->array[i]->type == TK_COMMAND)
			dyntree_add(root, dyntree_new(tklist->array[i]->type, tklist->array[i]->value));
		i++;
	}
	return (root);
}
