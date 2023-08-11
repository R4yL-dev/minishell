/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 22:01:18 by lray              #+#    #+#             */
/*   Updated: 2023/08/11 23:27:21 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef TOKEN_H
# define TOKEN_H

typedef struct s_token
{
	int		type;
	char	*value;
}	t_token;

t_token	*token_new(int type, char *value);
void	token_free(t_token *token);

#endif
