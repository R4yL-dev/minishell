/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_var.c                                      :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 19:49:33 by lray              #+#    #+#             */
/*   Updated: 2023/10/13 10:57:07 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	process_func(t_ctx *ctx, t_dyntree *root, int *i_str, char *quote);
static int	process_var_spe(t_ctx *ctx, t_dyntree *root, int *i_str);
static void	process_quotes(t_dyntree *root, char *quote, int *i_str);
static int	process_var(t_ctx *ctx, t_dyntree *root, int *i_str);

int	replace_var(t_dyntree *root, t_ctx *ctx)
{
	size_t	i_child;
	int		i_str;
	char	quote;

	quote = 0;
	i_str = 0;
	if (root->type == TK_COMMAND || \
	root->type == TK_ARGUMENT || root->type == TK_FILE)
		process_func(ctx, root, &i_str, &quote);
	i_child = 0;
	while (i_child < root->num_children)
	{
		if (!replace_var(root->children[i_child++], ctx))
			return (0);
	}
	return (1);
}

static void	process_func(t_ctx *ctx, t_dyntree *root, int *i_str, char *quote)
{
	while (root->value[*i_str] != '\0')
	{
		if (is_quote(root->value[*i_str]))
			process_quotes(root, quote, i_str);
		if ((*quote == 0 || *quote == '"') && \
		(root->value[*i_str] == '$' && root->value[*i_str + 1] == '?'))
			process_var_spe(ctx, root, i_str);
		if ((*quote == 0 || *quote == '"') && root->value[*i_str] == '$')
			process_var(ctx, root, i_str);
		if (*i_str >= 0)
		{
			if (root->value[*i_str] == '\0')
				break ;
		}
		(*i_str)++;
	}
}

static void	process_quotes(t_dyntree *root, char *quote, int *i_str)
{
	if (*quote == 0)
		*quote = root->value[*i_str];
	else if (root->value[*i_str] == *quote)
		quote = 0;
}

static int	process_var_spe(t_ctx *ctx, t_dyntree *root, int *i_str)
{
	char	*res;

	res = NULL;
	res = ft_itoa(ctx->ret_code);
	if (!res)
		return (0);
	search_and_replace(&root->value, "$?", res, i_str);
	free(res);
	return (1);
}

static int	process_var(t_ctx *ctx, t_dyntree *root, int *i_str)
{
	char	*varname;
	int		pos;

	varname = NULL;
	varname = make_varname(varname, root->value, (size_t)*i_str);
	pos = grpvar_has(ctx->grpvar, GRPVAR_GLOBAL, varname);
	varname = add_dollar(varname);
	if (pos == -1)
		root->value = search_and_replace(&root->value, varname, NULL, i_str);
	else
		root->value = search_and_replace(&root->value, varname, \
		ctx->grpvar->global->array[pos]->value, i_str);
	free(varname);
	return (1);
}
