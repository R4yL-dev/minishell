/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:19:37 by lray              #+#    #+#             */
/*   Updated: 2023/10/31 20:18:24 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAND_H

# include <sys/types.h>
# include <dirent.h>

int		expand(t_ctx *ctx);

int		replace_var(t_dyntree *root, t_ctx *ctx);
char	*search_and_replace(char **value, char *varname, char *res, int *i);
char	*make_varname(char *varname, char *value, size_t i);
char	*init_varname(char *varname);
char	*add_char(char *varname, char c);
char	*add_dollar(char *varname);
int		delete_quotes(t_dyntree *root);
int		valide_tree(t_ctx *ctx, t_dyntree *root);
int		replace_builtins(t_dyntree *root, t_ctx *ctx);

#endif
