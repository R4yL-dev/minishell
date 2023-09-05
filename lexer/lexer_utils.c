/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 01:31:05 by lray              #+#    #+#             */
/*   Updated: 2023/09/05 15:07:11 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_only_space(char *input)
{
	int	nbr_space;
	int	i;

	i = 0;
	nbr_space = 0;
	while (input[i])
	{
		if (input[i] == ' ')
			nbr_space++;
		i++;
	}
	if (nbr_space == i)
		return (0);
	return (1);
}

int	is_redirect(char *token)
{
	if (token && ft_strlen(token) == 1 && \
		(ft_strncmp(token, "<", 1) == 0 || ft_strncmp(token, ">", 1) == 0))
		return (1);
	return (0);
}

int is_pipe(char *token)
{
	if (token && ft_strlen(token) == 1 && ft_strncmp(token, "|", 1) == 0)
		return (1);
	return (0);
}
