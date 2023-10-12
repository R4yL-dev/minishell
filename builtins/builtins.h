/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:59:04 by lray              #+#    #+#             */
/*   Updated: 2023/10/11 14:30:47 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

int	builtin_showctx(char **argv, t_ctx *ctx);
int	builtin_echo(char **argv, t_ctx *ctx);
int	builtin_pwd(char **argv, t_ctx *ctx);
int	builtin_exit(char **argv, t_ctx *ctx);

#endif
