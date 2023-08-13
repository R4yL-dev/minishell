/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 19:13:07 by lray              #+#    #+#             */
/*   Updated: 2023/08/13 18:52:06 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>

# include "lexer/token.h"
# include "lexer/dyntklist.h"
# include "parser/tree.h"
# include "parser/dyntree.h"
# include "exec/dynarrstr.h"

# include "libft/libft.h"
# include "prompt/prompt.h"
# include "lexer/lexer.h"
# include "parser/parser.h"
# include "exec/exec.h"

void	free_split(char **splitted_arr);

void	db_show_tree(t_dyntree *root, int depth);

#endif
