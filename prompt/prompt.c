/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 19:19:00 by lray              #+#    #+#             */
/*   Updated: 2023/11/02 17:05:13 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*prompt_get(void)
{
	char	*input;

	input = readline("MiniShrek$ ");
	if (input != NULL && input[0] != '\0' && !str_is_only_space(input))
		add_history(input);
	return (input);
}
