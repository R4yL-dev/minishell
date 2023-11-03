/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_tklist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:32:26 by lray              #+#    #+#             */
/*   Updated: 2023/10/30 12:44:37 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*process_value(char *input, int *i, char *quote);

int	add_to_tklist(char *input, int *i, t_dyntklist *tklist, int tktype)
{
	char	*value;
	char	quote;

	quote = 0;
	value = process_value(input, i, &quote);
	dyntklist_add(tklist, tktype, value);
	free (value);
	return (1);
}

static char	*process_value(char *input, int *i, char *quote)
{
	char	*value;
	size_t	value_len;

	value = NULL;
	value_len = 0;
	value = value_init(value);
	while (input[*i])
	{
		if (*quote == 0)
		{
			if (input[*i] == ' ' || is_redirect(input[*i]))
				break ;
			value = value_add(value, &value_len, input[*i]);
			if (is_quote(input[*i]))
				*quote = input[*i];
		}
		else
		{
			value = value_add(value, &value_len, input[*i]);
			if (input[*i] == *quote)
				*quote = 0;
		}
		(*i)++;
	}
	return (value);
}
