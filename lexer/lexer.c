/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 23:26:56 by lray              #+#    #+#             */
/*   Updated: 2023/10/07 21:55:07 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	skip_space(char *input, int *i);
static int	add_redirect(char *input, t_dyntklist *tklist, int *i);
static int	add_file(char *input, t_dyntklist *tklist, int *i);
static int	add_cmd(char *input, t_dyntklist *tklist, int *i);
static int	add_arg(char *input, t_dyntklist *tklist, int *i);

int	lexer(t_ctx *ctx)
{
	int i;
	int in_cmd;

	ctx->tklist = dyntklist_init(ctx->tklist);
	if (ctx->tklist == NULL)
		return (0);
	in_cmd = 0;
	i = 0;
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
			}
			else
			{
				if (add_redirect(ctx->input, ctx->tklist, &i) == 0)
					return (0);
				skip_space(ctx->input, &i);
				if (add_file(ctx->input, ctx->tklist, &i) == 0)
					return (0);
			}
		}
		else if (in_cmd == 0)
		{
			if (add_cmd(ctx->input, ctx->tklist, &i) == 0)
				return (0);
			in_cmd = 1;
		}
		else
		{
			if (add_arg(ctx->input, ctx->tklist, &i) == 0)
				return (0);
		}
		i++;
	}
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

static int	add_file(char *input, t_dyntklist *tklist, int *i)
{
	char	*value;
	size_t	value_len;

	value = NULL;
	value = malloc(sizeof(char) * 1);
	if (value == NULL)
	{
		ft_puterror("Malloc failed");
		return (0);
	}
	value[0] = '\0';
	while (input[*i] != '\0' && input[*i] != ' ' && !is_redirect(input[*i]))
	{
		value_len = ft_strlen(value) + 1;
		value = ft_realloc(value, value_len * sizeof(char), value_len + 1 * sizeof(char));
		if (value == NULL)
		{
			ft_puterror("Realloc failed");
			return (0);
		}
		ft_strlcat(value, &input[*i], value_len + 1);
		(*i)++;
	}
	(*i)--;
	dyntklist_add(tklist, TK_FILE, value);
	free(value);
	return (1);
}

static int	add_cmd(char *input, t_dyntklist *tklist, int *i)
{
	char	*value;
	size_t	value_len;

	value = malloc(sizeof(char) * 1);
	if (value == NULL)
	{
		ft_puterror("Malloc failed");
		return (0);
	}
	value[0] = '\0';
	while (input[*i] != '\0' && input[*i] != ' ' && !is_redirect(input[*i]))
	{
		value_len = ft_strlen(value) + 1;
		value = ft_realloc(value, value_len * sizeof(char), value_len + 1 * sizeof(char));
		if (value == NULL)
		{
			ft_puterror("Realloc failed");
			return (0);
		}
		ft_strlcat(value, &input[*i], value_len + 1);
		(*i)++;
	}
	(*i)--;
	dyntklist_add(tklist, TK_COMMAND, value);
	free(value);
	return (1);
}

static int	add_arg(char *input, t_dyntklist *tklist, int *i)
{
	char	*value;
	size_t	value_len;

	value = malloc(sizeof(char) * 1);
	if (value == NULL)
	{
		ft_puterror("Malloc failed");
		return (0);
	}
	*value = '\0';
	while (input[*i] != '\0' && input[*i] != ' ' && !is_redirect(input[*i]))
	{
		value_len = ft_strlen(value) + 1;
		value = ft_realloc(value, value_len * sizeof(char), value_len + 1 * sizeof(char));
		if (value == NULL)
		{
			ft_puterror("Realloc failed");
			return (0);
		}
		ft_strlcat(value, &input[*i], value_len + 1);
		(*i)++;
	}
	(*i)--;
	dyntklist_add(tklist, TK_ARGUMENT, value);
	free(value);
	return (1);
}
