/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 23:26:51 by lray              #+#    #+#             */
/*   Updated: 2023/08/10 01:54:42 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

enum	e_token_type
{
	TK_COMMAND,
	TK_ARGUMENT,
};

t_tklist	*lexer(char *input);
char		*trim_and_condense_string(const char *input);

#endif
