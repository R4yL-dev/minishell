/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 01:31:05 by lray              #+#    #+#             */
/*   Updated: 2023/10/30 12:16:53 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_redirect(char token)
{
	if (token == '<' || token == '>' || token == '|')
		return (1);
	return (0);
}

int	is_pipe(char token)
{
	if (token == '|')
		return (1);
	return (0);
}

int	is_quote(char c)
{
	if (c == '\'' || c == '"')
		return (1);
	return (0);
}

char	*value_init(char *value)
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

char	*value_add(char *value, size_t *value_len, char c)
{
	(*value_len)++;
	value = ft_realloc(value, \
	sizeof(char) * (*value_len), sizeof(char) * ((*value_len) + 1));
	value[(*value_len)] = '\0';
	if (value == NULL)
	{
		ft_puterror("Realloc failed");
		return (NULL);
	}
	if (value[0] == '\0')
		value = ft_memcpy(value, &c, (*value_len));
	else
		value = add_char_to_string(value, c);
	return (value);
}
