/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 23:26:51 by lray              #+#    #+#             */
/*   Updated: 2023/10/30 12:33:42 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

int		lexer(t_ctx *ctx);

int		add_redirect(t_ctx *ctx, t_dyntklist *tklist, int *i);
int		add_to_tklist(char *input, int *i, t_dyntklist *tklist, int tktype);

int		is_redirect(char token);
int		is_pipe(char token);
int		is_quote(char c);
char	*value_init(char *value);
char	*value_add(char *value, size_t *value_len, char c);

#endif
