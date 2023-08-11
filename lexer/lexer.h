/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 23:26:51 by lray              #+#    #+#             */
/*   Updated: 2023/08/11 23:27:27 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

enum	e_token_type
{
	TK_COMMAND,
	TK_ARGUMENT,
	TK_UNSET,
};

t_dyntklist	*lexer(char *input);
char		*trim_and_condense_string(const char *input);

#endif
