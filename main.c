/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 19:08:50 by lray              #+#    #+#             */
/*   Updated: 2023/08/11 23:26:46 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	FIXME:
		- Segfault when input is only space
*/

int	main(void)
{
	char		*input;
	t_dyntklist	*tklist;
	t_tree_node	*tree;

	while (1)
	{
		input = prompt_get();
		if (input == NULL)
			continue ;
		tklist = lexer(input);
		tree = parser(tklist);
		exec(tree);
	}
	clear_history();
	return (0);
}
