/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 19:08:50 by lray              #+#    #+#             */
/*   Updated: 2023/08/11 19:39:23 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int	main(void)
{
	char		*input;
	t_tklist	*tklist;
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

/* int main(void)
{
	t_dynarrstr	*dynarr;

	dynarr = NULL;
	dynarr = dynarrstr_init(dynarr);
	dynarrstr_add(dynarr, "ls");
	dynarrstr_add(dynarr, "-l");
	dynarrstr_add(dynarr, "-a");
	dynarrstr_add(dynarr, "-t");
	dynarrstr_show(dynarr);
	dynarrstr_free(dynarr);
	return (0);
} */
