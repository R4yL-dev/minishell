/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 19:08:50 by lray              #+#    #+#             */
/*   Updated: 2023/08/06 22:13:42 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
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
		free_split(splitted_input);
	}
	clear_history();
	return (0);
}
