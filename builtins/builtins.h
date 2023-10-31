/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:59:04 by lray              #+#    #+#             */
/*   Updated: 2023/10/31 00:30:35 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

int		builtin_showctx(char **argv, t_ctx *ctx);
int		builtin_echo(char **argv, t_ctx *ctx);
int		builtin_pwd(char **argv, t_ctx *ctx);
int		builtin_exit(char **argv, t_ctx *ctx);
int		builtin_export(char **argv, t_ctx *ctx);
int		builtin_clear(char **argv, t_ctx *ctx);

// export_utils.c
int		tablen(char **tab);
char	**copy_names(t_lstvar *lstvar);
char	**sort_names(char **list, t_lstvar *lstvar);
void	call_names_alpha(char **sorted_list, t_lstvar *lstvar);



#endif
