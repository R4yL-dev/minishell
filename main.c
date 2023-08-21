/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 19:08:50 by lray              #+#    #+#             */
/*   Updated: 2023/08/19 12:40:31 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_line(char *input, t_dyntklist *tklist, t_dyntree *tree);

/*
	/!\ /!\ /!\
	Il ne faut jamais oublier de set input, tklist et tree
		a NULL au début de la main loop.
	Si il ne sont pas set de la sorte, n'importe quelle commande
		après une commande inconnue déclanche un segfault.
	/!\ /!\ /!\

	FIXME:
		- Lorsque nous entrons un ou des '/', ne reagit pas comme Bash.
*/

int	main(void)
{
	char		*input;
	t_dyntklist	*tklist;
	t_dyntree	*tree;

	printf("\e[1;1H\e[2J");
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
		if (exec(tree) == 0)
		{
			free_line(input, tklist, tree);
			continue ;
		}
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
