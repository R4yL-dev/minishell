/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 23:26:56 by lray              #+#    #+#             */
/*   Updated: 2023/08/14 01:41:16 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static t_dyntklist	*lexer_run(char *input);
static int	is_only_space(char *input);

t_dyntklist	*lexer(char *input)
{
	char		*cleaned_input;
	t_dyntklist	*tklist;

	if (is_only_space(input) == 0)
		return (NULL);
	cleaned_input = trim_and_condense_string(input);
	tklist = lexer_run(cleaned_input);
	free(cleaned_input);
	return (tklist);
}

static t_dyntklist	*lexer_run(char *input)
{
	char		**splitted_input;
	t_dyntklist	*tklist;
	int			i;

	tklist = NULL;
	tklist = dyntklist_init(tklist);
	if (tklist == NULL)
	{
		perror("Token list initialization failed");
		return (NULL);
	}
	splitted_input = ft_split(input, ' ');
	if (splitted_input == NULL)
	{
		perror("Split failed");
		return (NULL);
	}
	i = 0;
	while(splitted_input[i])
	{
		if (i == 0)
		{
			if (dyntklist_add(tklist, TK_COMMAND, splitted_input[i]) == 0)
			{
				ft_freesplit(splitted_input);
				return (NULL);
			}
		}
		else
		{
			if (dyntklist_add(tklist, TK_ARGUMENT, splitted_input[i]) == 0)
			{
				ft_freesplit(splitted_input);
				return (NULL);
			}
		}
		i++;
	}
	ft_freesplit(splitted_input);
	return (tklist);
}

static int	is_only_space(char *input)
{
	int	nbr_space;
	int	i;

	i = 0;
	nbr_space = 0;
	while (input[i])
	{
		if (input[i] == ' ')
			nbr_space++;
		i++;
	}
	if (nbr_space == i)
		return (0);
	return (1);
}
