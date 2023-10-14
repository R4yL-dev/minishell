/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 23:26:56 by lray              #+#    #+#             */
/*   Updated: 2023/10/14 14:42:18 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	skip_space(char *input, int *i);
static int	add_redirect(char *input, t_dyntklist *tklist, int *i);
static int	add_to_tklist(char *input, int *i, t_dyntklist *tklist, int tktype);
static char	*value_init(char *value);
static char	*value_add(char *value, size_t *value_len, char c);
static int	is_quote(char c);

int	lexer(t_ctx *ctx)
{
	int i;
	int in_cmd;

	in_cmd = 0;
	i = 0;
	ctx->tklist = dyntklist_init(ctx->tklist);
	if (ctx->tklist == NULL)
		return (0);
	while (ctx->input[i] != '\0')
	{
		skip_space(ctx->input, &i);
		if (ctx->input[i] == '\0')
			break ;
		if (is_redirect(ctx->input[i]))
		{
			if (is_pipe(ctx->input[i]))
			{
				dyntklist_add(ctx->tklist, TK_PIPE, "|");
				in_cmd = 0;
				++i;
			}
			else
			{
				if (add_redirect(ctx->input, ctx->tklist, &i) == 0)
					return (0);
				skip_space(ctx->input, &i);
				if (add_to_tklist(ctx->input, &i, ctx->tklist, TK_FILE) == 0)
					return (0);
			}
		}
		else if (in_cmd == 0)
		{
			if (add_to_tklist(ctx->input, &i, ctx->tklist, TK_COMMAND) == 0)
				return (0);
			in_cmd = 1;
		}
		else
		{
			if (add_to_tklist(ctx->input, &i, ctx->tklist, TK_ARGUMENT) == 0)
				return (0);
		}
	}
	if (ctx->tklist->size == 0)
		return (0);
	return (1);
}

static void	skip_space(char *input, int *i)
{
	while (input[*i] != '\0' && input[*i] == ' ')
		(*i)++;
}

static int	add_redirect(char *input, t_dyntklist *tklist, int *i)
{
	char *value;

	if (input[(*i) + 1] == '\0')
	{
		ft_puterror("Syntax error");
		return (0);
	}
	else if (input[*i] != input[(*i) + 1] && is_redirect(input[(*i) + 1]))
	{
		ft_puterror("Syntax error");
		return (0);
	}
	else if (is_redirect(input[(*i) + 2]))
	{
		ft_puterror("Syntax error");
		return (0);
	}
	else if (input[*i] == input[(*i) + 1])
	{
		value = malloc(sizeof(char) * 3);
		if (value == NULL)
		{
			ft_puterror("Malloc failed");
			return (0);
		}
		value[0] = input[*i];
		value[1] = input[*i];
		value[2] = '\0';
		dyntklist_add(tklist, TK_REDIRECTION, value);
		free(value);
		(*i) += 2;
		return (1);
	}
	else
	{
		value = malloc(sizeof(char) * 2);
		if (value == NULL)
		{
			ft_puterror("Malloc failed");
			return (0);
		}
		value[0] = input[*i];
		value[1] = '\0';
		dyntklist_add(tklist, TK_REDIRECTION, value);
		free(value);
		(*i)++;
		return (1);
	}
}

static int	add_to_tklist(char *input, int *i, t_dyntklist *tklist, int tktype)
{
	char	*value;
	size_t	value_len;
	char	quote;

	quote = 0;
	value = NULL;
	value_len = 0;
	value = value_init(value);
	if (!value)
		return (0);
	while (input[*i])
	{
		if (quote == 0)
		{
			if (input[*i] == ' ' || is_redirect(input[*i]))
				break ;
			value = value_add(value, &value_len, input[*i]);
			if (is_quote(input[*i]))
				quote = input[*i];
		}
		else
		{
			value = value_add(value, &value_len, input[*i]);
			if (input[*i] == quote)
				quote = 0;
		}
		(*i)++;
	}
	dyntklist_add(tklist, tktype, value);
	free (value);
	return (1);
}

static char	*value_init(char *value)
{
	value = malloc(sizeof(char));
	if (!value)
	{
		ft_puterror("Malloc failed");
		return (NULL);
	}
	value[0] = '\0';
	return (value);
}

static char	*value_add(char *value, size_t *value_len, char c)
{
	(*value_len)++;
	value = ft_realloc(value, sizeof(char) * (*value_len), sizeof(char) * ((*value_len) + 1));
	if (value == NULL)
	{
		ft_puterror("Realloc failed");
		return (0);
	}
	ft_strlcat(value, &c, (*value_len) + 1);
	return (value);
}

static int	is_quote(char c)
{
	if (c == '\'' || c == '"')
		return (1);
	return (0);
}
