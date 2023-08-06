/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 19:08:50 by lray              #+#    #+#             */
/*   Updated: 2023/08/06 23:00:06 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	(void)	argc;
	(void)	argv;
	char	*input;
	char	**splitted_input;

	while (1)
	{
		input = prompt_get();
		if (input == NULL)
			continue ;
		splitted_input = ft_split(input, ' ');
		free(input);
		if (ft_strncmp(splitted_input[0], "exit", ft_strlen("exit")) == 0)
		{
			free_split(splitted_input);
			break ;
		}
		execmd(splitted_input, envp);
		free_split(splitted_input);
	}
	clear_history();
	return (0);
}
