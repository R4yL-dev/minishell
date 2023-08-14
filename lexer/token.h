/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 22:01:18 by lray              #+#    #+#             */
/*   Updated: 2023/08/14 02:09:34 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

typedef struct s_token
{
	int		type;
	char	*value;
}	t_token;

enum	e_token_type
{
	TK_COMMAND,
	TK_ARGUMENT,
	TK_FILE,
	TK_REDIRECTION,
	TK_PIPE,
};

t_token	*token_new(int type, char *value);
void	token_free(t_token *token);

#endif
