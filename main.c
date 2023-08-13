/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 19:08:50 by lray              #+#    #+#             */
/*   Updated: 2023/08/13 21:21:52 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_line(char *input, t_dyntklist *tklist, t_dyntree *tree);

int	main(void)
{
	char		*input;
	t_dyntklist	*tklist;
	t_dyntree	*tree;

	input = NULL;
	tklist = NULL;
	tree = NULL;
	while (1)
	{
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
		exec(tree);
		free_line(input, tklist, tree);
	}
	clear_history();
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

/* int	main(void)
{
	t_dyntree	*root;

	root = NULL;
	root = dyntree_new(TK_PIPE, "|");
	dyntree_add(root, dyntree_new(TK_COMMAND, "grep"));
	dyntree_add(root->children[0], dyntree_new(TK_REDIRECTION, ">"));
	dyntree_add(root->children[0]->children[0], dyntree_new(TK_FILE, "infile.txt"));
	dyntree_add(root->children[0], dyntree_new(TK_ARGUMENT, "test"));
	dyntree_add(root, dyntree_new(TK_COMMAND, "sort"));
	dyntree_add(root, dyntree_new(TK_COMMAND, "wc"));
	dyntree_add(root->children[2], dyntree_new(TK_ARGUMENT, "-l"));
	dyntree_add(root->children[2], dyntree_new(TK_REDIRECTION, ">"));
	dyntree_add(root->children[2]->children[1], dyntree_new(TK_FILE, "outfile.txt"));
	db_show_tree(root, 0);
	dyntree_free(root);
	return (0);
} */

