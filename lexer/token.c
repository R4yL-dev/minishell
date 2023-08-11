/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 21:57:17 by lray              #+#    #+#             */
/*   Updated: 2023/08/11 23:27:23 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token	*token_new(int type, char *value)
{
	t_token	*token;

	token = malloc(sizeof(t_token) * 1);
	if (token == NULL)
		return (NULL);
	token->type = type;
	token->value = ft_strdup(value);
	return (token);
}

void	token_free(t_token *token)
{
	if (token != NULL)
	{
		free(token->value);
		free(token);
	}
}
