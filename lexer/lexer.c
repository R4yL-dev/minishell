/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 23:26:56 by lray              #+#    #+#             */
/*   Updated: 2023/08/10 02:31:24 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static t_tklist	*lexer_run(char *input);
static int	is_only_space(char *input);

/*
	TODO:
		- Il faut que le lexer gère les erreurs
*/
t_tklist	*lexer(char *input)
{
	char		*cleaned_input;
	t_tklist	*tklist;

	if (is_only_space(input) == 0)
		return (NULL);
	cleaned_input = trim_and_condense_string(input);
	tklist = lexer_run(cleaned_input);
	free(cleaned_input);
	return (tklist);
}

/*
	TODO:
		handle split error
*/
static t_tklist	*lexer_run(char *input)
{
	char		**splitted_input;
	t_tklist	*tklist;
	int			i;

	tklist = NULL;
	splitted_input = ft_split(input, ' ');
	if (splitted_input == NULL)
		return (NULL);
	i = 0;
	while(splitted_input[i])
	{
		if (splitted_input[i][0] == '-')
		{
			if (tklist == NULL)
				tklist = tklist_new(splitted_input[i], TK_ARGUMENT);
			else
				tklist_add(&tklist, tklist_new(splitted_input[i], TK_ARGUMENT));
		}
		else
		{
			if (tklist == NULL)
				tklist = tklist_new(splitted_input[i], TK_COMMAND);
			else
				tklist_add(&tklist, tklist_new(splitted_input[i], TK_COMMAND));
		}
		i++;
	}
	ft_freesplit(splitted_input);
	return (tklist);
}

static int	is_only_space(char *input)
{
	size_t	nbr_space;
	size_t	i;

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
