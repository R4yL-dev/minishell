/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_redirect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:17:32 by lray              #+#    #+#             */
/*   Updated: 2023/11/02 13:04:01 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	make_double_redirect(t_ctx *c, t_dyntklist *tkl, char *v, int *i);
static int	make_simple_redirect(t_ctx *c, t_dyntklist *tkl, char *v, int *i);

int	add_redirect(t_ctx *ctx, t_dyntklist *tklist, int *i)
{
	char	*value;

	value = NULL;
	if (ctx->input[(*i) + 1] == '\0')
	{
		g_code = 2;
		ft_puterror("Syntax error");
		return (0);
	}
	else if (ctx->input[*i] != ctx->input[(*i) + 1] \
	&& is_redirect(ctx->input[(*i) + 1]))
	{
		g_code = 2;
		ft_puterror("Syntax error");
		return (0);
	}
	else if (ctx->input[*i] == ctx->input[(*i) + 1])
		return (make_double_redirect(ctx, tklist, value, i));
	else
		return (make_simple_redirect(ctx, tklist, value, i));
}

static int	make_double_redirect(t_ctx *c, t_dyntklist *tkl, char *v, int *i)
{
	v = malloc(sizeof(char) * 3);
	if (v == NULL)
	{
		ft_puterror("Malloc failed");
		return (0);
	}
	v[0] = c->input[*i];
	v[1] = c->input[*i];
	v[2] = '\0';
	dyntklist_add(tkl, TK_REDIRECTION, v);
	free(v);
	(*i) += 2;
	return (1);
}

static int	make_simple_redirect(t_ctx *c, t_dyntklist *tkl, char *v, int *i)
{
	v = malloc(sizeof(char) * 2);
	if (v == NULL)
	{
		ft_puterror("Malloc failed");
		return (0);
	}
	v[0] = c->input[*i];
	v[1] = '\0';
	dyntklist_add(tkl, TK_REDIRECTION, v);
	free(v);
	(*i)++;
	return (1);
}
