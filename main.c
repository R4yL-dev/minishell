/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 19:08:50 by lray              #+#    #+#             */
/*   Updated: 2023/08/10 15:31:58 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


/*
	TODO:
		- Ajouter parser
		- Ajouter exec. Actuellement, c'est une focntion à la zeub pour tester
*/
int	main(int argc, char **argv, char **envp)
{
	(void)		argc;
	(void)		argv;
	(void)		envp;
	char		*input;
	t_tklist	*tklist;
	t_tree_node	*tree;
	//char		**splitted_input;

	while (1)
	{
		input = prompt_get();
		if (input == NULL)
			continue ;
		tklist = lexer(input);
		tree = parser(tklist);
		db_show_tree(tree, 0);
/* 		splitted_input = ft_split(input, ' ');
		exec(splitted_input, envp);
		free_split(splitted_input); */
	}
	clear_history();
	return (0);
}
