/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_builtins.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:16:32 by lray              #+#    #+#             */
/*   Updated: 2023/10/09 20:50:41 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_BUILTINS_H
# define REPLACE_BUILTINS_H

# include <sys/types.h>
# include <dirent.h>

int	replace_builtins(t_dyntree *root, t_ctx *ctx);

#endif
