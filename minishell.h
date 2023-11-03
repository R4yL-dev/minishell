/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 19:13:07 by lray              #+#    #+#             */
/*   Updated: 2023/11/02 13:02:35 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <errno.h>

# include "ctx/ctx.h"
# include "vars/var.h"
# include "vars/lstvar.h"
# include "vars/grpvar.h"
# include "builtins/lstbuiltins.h"
# include "builtins/builtins.h"
# include "lexer/token.h"
# include "lexer/dyntklist.h"
# include "parser/dyntree.h"
# include "exec/env.h"
# include "exec/pipes_list.h"
# include "exec/dynarrstr.h"

# include "signals/signals.h"

# include "libft/libft.h"
# include "prompt/prompt.h"
# include "lexer/lexer.h"
# include "expand/expand.h"
# include "parser/parser.h"
# include "exec/exec.h"

extern int	g_code;

void	free_split(char **splitted_arr);

char	**arrcpy(char **arr, int size);

void	ft_puterror(char *msg);

char	*add_char_to_string(char *str, char c);

int		str_is_only_space(char *str);

void	arr_show(char **arr);

int		ft_abs(int n);

#endif
