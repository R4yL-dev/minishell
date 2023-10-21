/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:59:04 by lray              #+#    #+#             */
/*   Updated: 2023/10/21 19:03:49 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

int	builtin_showctx(char **argv, t_ctx *ctx);
int	builtin_echo(char **argv, t_ctx *ctx);
int	builtin_pwd(char **argv, t_ctx *ctx);
int	builtin_exit(char **argv, t_ctx *ctx);
int	builtin_unset(char **argv, t_ctx *ctx);
int	builtin_clear(char **argv, t_ctx *ctx);

#endif
