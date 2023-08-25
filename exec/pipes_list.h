/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:41:13 by lray              #+#    #+#             */
/*   Updated: 2023/08/22 16:44:43 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPES_LIST_H
# define PIPES_LIST_H

/**
 * @brief Creates a list of pipes.
 *
 * This function creates a list of pipes, represented as an array of integer arrays.
 * The number of pipes to create is specified by the `num_pipes` parameter. If the
 * `num_pipes` parameter is less than or equal to 0, this function returns `NULL`.
 * If any allocation or pipe creation fails, this function returns `NULL`.
 *
 * @param num_pipes The number of pipes to create.
 * @return An array of integer arrays representing the pipes, or `NULL` if any error occurs.
 */
int		**pipes_list_create(int num_pipes);

/**
 * @brief Displays information about a list of pipes.
 *
 * This function displays information about a list of pipes, represented as an array
 * of integer arrays. The number of pipes to display is specified by the `num_pipes`
 * parameter. If the `num_pipes` parameter is less than or equal to 0, this function
 * does nothing.
 *
 * @param pipes_list An array of integer arrays representing the pipes.
 * @param num_pipes The number of pipes to display.
 */
void	pipes_list_show(int **pipes_list, int num_pipes);

/**
 * @brief Frees a list of pipes.
 *
 * This function frees a list of pipes, represented as an array of integer arrays.
 * The number of pipes to free is specified by the `num_pipes` parameter. If the
 * `num_pipes` parameter is less than or equal to 0, this function does nothing.
 *
 * @param pipes_list An array of integer arrays representing the pipes.
 * @param num_pipes The number of pipes to free.
 */
void	pipes_list_free(int **pipes_list, int num_pipes);

#endif
