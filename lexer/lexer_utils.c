/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 01:31:05 by lray              #+#    #+#             */
/*   Updated: 2023/09/22 17:16:33 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_redirect(char token)
{
	if (token == '<' || token == '>' || token == '|')
		return (1);
	return (0);
}

int	is_pipe(char token)
{
	if (token == '|')
		return (1);
	return (0);
}
