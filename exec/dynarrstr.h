/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynarrstr.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:27:12 by lray              #+#    #+#             */
/*   Updated: 2023/08/22 16:49:58 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DYNARRSTR_H
# define DYNARRSTR_H

typedef struct s_dynarrstr
{
	char	**array;
	size_t	size;
}	t_dynarrstr;

/**
 * @brief Initializes a dynamic array of strings.
 *
 * This function initializes a dynamic array of strings, represented as a `t_dynarrstr`
 * structure. If the `dynarr` parameter is `NULL`, this function allocates memory for
 * the structure and its fields. If any allocation fails, this function returns `NULL`.
 * Otherwise, this function initializes the `array` field to a single empty string and
 * sets the `size` field to 0.
 *
 * @param dynarr A pointer to the `t_dynarrstr` structure to initialize, or `NULL`.
 * @return A pointer to the initialized `t_dynarrstr` structure, or `NULL` if any error occurs.
 */
t_dynarrstr	*dynarrstr_init(t_dynarrstr *dynarr);

/**
 * @brief Adds a string to a dynamic array of strings.
 *
 * This function adds a string to a dynamic array of strings, represented as a `t_dynarrstr`
 * structure. If the `dynarr` or `value` parameter is `NULL`, this function returns 0.
 * Otherwise, this function reallocates memory for the array and the new string, and copies
 * the string into the array. If any allocation fails, this function returns 0.
 *
 * @param dynarr A pointer to the `t_dynarrstr` structure to add the string to.
 * @param value The string to add to the array.
 * @return 1 if the string was added successfully, or 0 if any error occurs.
 */
int			dynarrstr_add(t_dynarrstr *dynarr, char *value);

/**
 * @brief Displays the contents of a dynamic array of strings.
 *
 * This function displays the contents of a dynamic array of strings, represented as a
 * `t_dynarrstr` structure. If the `dynarr` parameter is `NULL`, this function does nothing.
 * Otherwise, this function prints the size of the array and the contents of each string
 * in the array, using `printf`.
 *
 * @param dynarr A pointer to the `t_dynarrstr` structure to display.
 */
void		dynarrstr_show(t_dynarrstr *dynarr);

/**
 * @brief Frees the memory used by a dynamic array of strings.
 *
 * This function frees the memory used by a dynamic array of strings, represented as a
 * `t_dynarrstr` structure. If the `dynarr` parameter is `NULL`, this function does nothing.
 * Otherwise, this function frees the memory used by each string in the array, and then
 * frees the memory used by the array itself. Finally, this function frees the memory used
 * by the `t_dynarrstr` structure.
 *
 * @param dynarr A pointer to the `t_dynarrstr` structure to free.
 */
void		dynarrstr_free(t_dynarrstr *dynarr);

#endif
