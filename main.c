/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 19:08:50 by lray              #+#    #+#             */
/*   Updated: 2023/08/06 19:52:01 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char	*input;

	while (1)
	{
		input = prompt_get();
		if (input == NULL)
		{
			continue ;
		}
		if (ft_strncmp(input, "exit", ft_strlen("exit")) == 0)
		{
			free(input);
			break ;
		}

		free(input);
	}
	clear_history();
	return (0);
}
