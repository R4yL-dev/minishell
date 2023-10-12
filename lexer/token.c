/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 21:57:17 by lray              #+#    #+#             */
/*   Updated: 2023/10/11 14:24:04 by lray             ###   ########.fr       */
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

void	token_show(t_token *token)
{
	printf("Type : ");
	if (token->type == 0)
		printf("TK_COMMAND");
	else if (token->type == 1)
		printf("TK_ARGUMENT");
	else if (token->type == 2)
		printf("TK_FILE");
	else if (token->type == 3)
		printf("TK_REDIRECTION");
	else if (token->type == 4)
		printf("TK_PIPE");
	else if (token->type == 5)
		printf("TK_BUILTINS");
	else
		printf("UNKNOW TOKEN (%d)", token->type);
	printf(" | Value : %s\n", token->value);
}

void	token_free(t_token *token)
{
	if (token != NULL)
	{
		free(token->value);
		free(token);
	}
}
