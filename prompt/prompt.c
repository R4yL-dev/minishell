/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 19:19:00 by lray              #+#    #+#             */
/*   Updated: 2023/08/14 01:49:39 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*prompt_get(void)
{
	char	*input;

	rl_on_new_line();
	input = readline("minishell$ ");
	if (input == NULL || ft_strlen(input) == 0)
	{
		free(input);
		return (NULL);
	}
	add_history(input);
	return (input);
}
