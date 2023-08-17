/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 23:26:56 by lray              #+#    #+#             */
/*   Updated: 2023/08/18 01:27:53 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static t_dyntklist	*lexer_run(char *input);
static int	is_only_space(char *input);
static char	**split_input(char *input);
static t_dyntklist *tokenize(char **splitted_input);
static int is_redirect(char *token);

t_dyntklist	*lexer(char *input)
{
	char		*cleaned_input;
	t_dyntklist	*tklist;

	if (is_only_space(input) == 0)
		return (NULL);
	cleaned_input = trim_and_condense_string(input);
	// TODO: get error
	tklist = lexer_run(cleaned_input);
	free(cleaned_input);
	return (tklist);
}

static t_dyntklist	*lexer_run(char *input)
{
	char		**splitted_input;
	t_dyntklist	*tklist;

	splitted_input = split_input(input);
	if (splitted_input == NULL)
		return (NULL);
	tklist = tokenize(splitted_input);
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

static char	**split_input(char *input)
{
	char		**splitted_input;

	splitted_input = ft_split(input, ' ');
	if (splitted_input == NULL)
	{
		perror("Split failed");
		return (NULL);
	}
	return (splitted_input);
}


/*
	TODO:
		- OK POUR LE MOMENT, j ai fait une batterie de test basique,
			mais  il faudra encore bien tester car c'est une étape crusiale
*/
static t_dyntklist *tokenize(char **splitted_input)
{
	t_dyntklist	*tklist;
	int			i;

	tklist = NULL;
	tklist = dyntklist_init(tklist);
	if (tklist == NULL)
	{
		ft_puterror("Token list initialization failed");
		return (NULL);
	}
	i = 0;
	while (is_redirect(splitted_input[i]))
	{
		dyntklist_add(tklist, TK_REDIRECTION, splitted_input[i++]);
		if (splitted_input[i] != NULL)
			dyntklist_add(tklist, TK_FILE, splitted_input[i++]);
		else
		{
			ft_puterror("syntax error");
			dyntklist_free(tklist);
			return (NULL);
		}
	}
	if (splitted_input[i] == NULL)
		return (tklist);
	dyntklist_add(tklist, TK_COMMAND, splitted_input[i]);
	i++;
	while (splitted_input[i])
	{
		if (is_redirect(splitted_input[i]))
		{
			dyntklist_add(tklist, TK_REDIRECTION, splitted_input[i++]);
			if (splitted_input[i] != NULL)
				dyntklist_add(tklist, TK_FILE, splitted_input[i++]);
			else
			{
				ft_puterror("syntax error");
				dyntklist_free(tklist);
				return (NULL);
			}
		}
		else
			dyntklist_add(tklist, TK_ARGUMENT, splitted_input[i++]);
	}
	return (tklist);
}

static int is_redirect(char *token)
{
	if (token && ft_strlen(token) == 1 && \
		(ft_strncmp(token, "<", 1) == 0 || ft_strncmp(token, ">", 1) == 0))
		return (1);
	else
		return (0);
}
