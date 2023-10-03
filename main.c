/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 19:08:50 by lray              #+#    #+#             */
/*   Updated: 2023/10/01 00:26:02 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_line(char *input, t_dyntklist *tklist, t_dyntree *tree);
static	void clean_quit(char *input, t_dyntklist *tklist, t_dyntree *tree, t_grpvar *grpvar);

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
	set_signals(NULL);
	while (1)
	{
		input = NULL;
		tklist = NULL;
		tree = NULL;
		input = prompt_get();
		if (input == NULL)
		{
			printf("exit\n");
			clean_quit(input, tklist, tree, grpvar);
		}
		else if (input[0] == '\0')
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
		if (expand(tree, grpvar))
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

static	void clean_quit(char *input, t_dyntklist *tklist, t_dyntree *tree, t_grpvar *grpvar)
{
	free_line(input, tklist, tree);
	grpvar_free(grpvar);
	clear_history();
	exit (0);
}