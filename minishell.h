/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 19:13:07 by lray              #+#    #+#             */
/*   Updated: 2023/08/18 00:46:33 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <errno.h>

# include "lexer/token.h"
# include "lexer/dyntklist.h"
# include "parser/dyntree.h"
# include "exec/dynarrstr.h"
# include "env/env.h"

# include "libft/libft.h"
# include "prompt/prompt.h"
# include "lexer/lexer.h"
# include "parser/parser.h"
# include "exec/exec.h"

void	free_split(char **splitted_arr);
void	ft_puterror(char *msg);

void	db_show_tree(t_dyntree *root, int depth);

#endif
