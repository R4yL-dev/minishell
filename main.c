/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 19:08:50 by lray              #+#    #+#             */
/*   Updated: 2023/08/10 02:55:23 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//static void	db_show_tklist(t_tklist *tklist);

int	main(int argc, char **argv, char **envp)
{
	(void)		argc;
	(void)		argv;
	char		*input;
	//t_tklist	*tklist;
	char		**splitted_input;

	while (1)
	{
		input = prompt_get();
		if (input == NULL)
			continue ;
		//tklist = lexer(input);
		//db_show_tklist(tklist);
		// Appeler le parser sur le résultat
		// Appeler execut sur le résulta du parsing
		splitted_input = ft_split(input, ' ');
		exec(splitted_input, envp);
		free_split(splitted_input);
	}
	clear_history();
	return (0);
}

/* static void	db_show_tklist(t_tklist *tklist)
{
	t_tklist	*tmp;

	tmp = tklist;
	while (tmp)
	{
		printf("value: %s\n", tmp->value);
		printf("type: %d\n", tmp->type);
		tmp = tmp->next;
	}
} */
