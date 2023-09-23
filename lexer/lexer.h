/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 23:26:51 by lray              #+#    #+#             */
/*   Updated: 2023/09/22 17:12:32 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

t_dyntklist	*lexer(char *input);
char		*trim_and_condense_string(const char *input);

int	is_redirect(char token);
int	is_pipe(char token);

#endif
