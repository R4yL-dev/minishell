/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:29:45 by lray              #+#    #+#             */
/*   Updated: 2023/10/30 13:46:17 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

int			parser(t_ctx *ctx);

t_dyntree	*exctract_root(t_dyntklist *tklist);
int			add_to_cmd(t_dyntklist *tklist, t_dyntree *root, int pos);
t_dyntree	*add_cmd_to_root(t_dyntklist *tklist, t_dyntree *root);

int			has_token_type(t_dyntklist *tklist, int token_type);

#endif
