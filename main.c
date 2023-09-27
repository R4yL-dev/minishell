/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 19:08:50 by lray              #+#    #+#             */
/*   Updated: 2023/09/27 13:33:42 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_line(char *input, t_dyntklist *tklist, t_dyntree *tree);

/*
	FIXME:
		- Bug lorsque l'input est /
		- Bug lorsque l'input est que des espaces
*/

int	main(int argc, char **argv, char **envp)
{
	char		*input;
	t_dyntklist	*tklist;
	t_dyntree	*tree;
	t_grpvar	*grpvar;
	(void)		argc;
	(void)		argv;

	printf("\e[1;1H\e[2J");
	printf("== INIT GROUP VAR ==\n");
	grpvar = grpvar_init(envp);
	grpvar_show(grpvar);
	printf("\n");
	while (1)
	{
		input = NULL;
		tklist = NULL;
		tree = NULL;
		input = prompt_get();
		if (input == NULL)
		{
			free_line(input, tklist, tree);
			continue ;
		}
		tklist = lexer(input);
		if (tklist == NULL)
		{
			free_line(input, tklist, tree);
			continue ;
		}
		tree = parser(tklist);
		if (tree == NULL)
		{
			free_line(input, tklist, tree);
			continue ;
		}
		exec(tree, grpvar);
		free_line(input, tklist, tree);
	}
	clear_history();
	grpvar_free(grpvar);
	return (0);
}

static void	free_line(char *input, t_dyntklist *tklist, t_dyntree *tree)
{
	free(input);
	input = NULL;
	dyntklist_free(tklist);
	tklist = NULL;
	dyntree_free(tree);
	tree = NULL;
}
