/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 19:13:07 by lray              #+#    #+#             */
/*   Updated: 2023/08/25 15:37:53 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <errno.h>

# include "lexer/token.h"
# include "lexer/dyntklist.h"
# include "parser/dyntree.h"
# include "exec/env_node.h"
# include "exec/pipes_list.h"
# include "exec/dynarrstr.h"
# include "env/env.h"

# include "libft/libft.h"
# include "prompt/prompt.h"
# include "lexer/lexer.h"
# include "parser/parser.h"
# include "exec/exec.h"

void	free_split(char **splitted_arr);

/**
 * @brief Copies an array of strings.
 *
 * This function copies an array of strings by allocating memory for each string in the
 * array and copying the contents of each string to the new array. If any allocation or
 * copying fails, this function returns NULL. Otherwise, this function returns a pointer
 * to the new array of strings.
 *
 * @param arr A pointer to the array of strings to copy.
 * @param size The size of the array.
 * @return A pointer to the new array of strings, or NULL if any error occurs.
 */
char **arrcyp(char **arr, int size);

void	ft_puterror(char *msg);

void	db_show_tree(t_dyntree *root, int depth);

#endif
