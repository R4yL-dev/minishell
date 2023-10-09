/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:29:53 by lray              #+#    #+#             */
/*   Updated: 2023/10/09 18:43:48 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static t_dyntree	*exctract_root(t_dyntklist *tklist);
static int			has_token_type(t_dyntklist *tklist, int token_type);
static int	add_to_cmd(t_dyntklist *tklist, t_dyntree *root, int pos);
static t_dyntree	*add_cmd_to_root(t_dyntklist *tklist, t_dyntree *root);

int	parser(t_ctx *ctx)
{
	size_t		i;
	int			last_pipe;

	ctx->tree = exctract_root(ctx->tklist);
	if (ctx->tree->type == TK_COMMAND || ctx->tree->type == TK_REDIRECTION)
		add_to_cmd(ctx->tklist, ctx->tree, 0);
	else if (ctx->tree->type == TK_PIPE)
	{
		add_cmd_to_root(ctx->tklist, ctx->tree);
		i = 0;
		last_pipe = 0;
		while (i < ctx->tree->numChildren)
		{
			last_pipe = add_to_cmd(ctx->tklist, ctx->tree->children[i], last_pipe) + 1;
			++i;
		}
	}
	else
	{
		ft_puterror("Unknow root");
		return (0);
	}
	return (1);
}

static t_dyntree	*exctract_root(t_dyntklist *tklist)
{
	t_dyntree	*root;
	int			i;

	root = NULL;
	i =  0;
	if (has_token_type(tklist, TK_PIPE) != -1)
	{
		while (tklist->array[i]->type != TK_PIPE)
			i++;
		root = dyntree_new(TK_PIPE, "|");
	}
	else if (has_token_type(tklist, TK_COMMAND) != -1)
	{
		while (tklist->array[i]->type != TK_COMMAND)
			i++;
		root = dyntree_new(tklist->array[i]->type, tklist->array[i]->value);
	}
	else if (has_token_type(tklist, TK_REDIRECTION) != -1)
	{
		while (tklist->array[i]->type != TK_REDIRECTION)
			i++;
		root = dyntree_new(tklist->array[i]->type, tklist->array[i]->value);
	}
	return (root);
}

static int	has_token_type(t_dyntklist *tklist, int token_type)
{
	int	pos;

	if (tklist == NULL || tklist->array == NULL || token_type < 0)
		return (-1);
	pos = 0;
	while (tklist->array[pos])
	{
		if (tklist->array[pos]->type == token_type)
			return (pos);
		pos++;
	}
	return (-1);
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
			++i;
	}
	return (i);
}

static t_dyntree	*add_cmd_to_root(t_dyntklist *tklist, t_dyntree *root)
{
	t_dyntklist **res;
	int			i;
	int			pos;

	res = dyntklist_split(tklist);
	i = 0;
	while (res[i])
	{
		pos = has_token_type(res[i], TK_COMMAND);
		if (pos != -1)
		{
			dyntree_add(root, dyntree_new(res[i]->array[pos]->type, res[i]->array[pos]->value));
			++i;
			continue ;
		}
		pos = has_token_type(res[i], TK_REDIRECTION);
		if (pos != -1)
		{
			dyntree_add(root, dyntree_new(res[i]->array[pos]->type, res[i]->array[pos]->value));
			++i;
			continue ;
		}
		else
			return (NULL);
	}
	dyntklist_split_free(res);
	return (root);
}
