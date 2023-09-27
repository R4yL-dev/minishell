/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:39:00 by lray              #+#    #+#             */
/*   Updated: 2023/09/26 16:08:35 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VAR_H
# define VAR_H

typedef struct s_var
{
	char	*name;
	char	*value;
}	t_var;

/**
 * Creates a new variable with the given name and value.
 *
 * @param name The name of the variable.
 * @param value The value of the variable.
 * @return A pointer to the new variable, or NULL if the name or value is NULL, or if the memory allocation fails.
 * @remarks The function allocates memory for the new variable using malloc(). The caller is responsible for freeing the memory using var_free().
 * @remarks If the name or value is NULL, the function prints an error message to stderr and returns NULL.
 */
t_var	*var_new(char *name, char *value);

/**
 * Prints the name and value of a variable to the console.
 *
 * @param var A pointer to the variable to show.
 * @remarks If the pointer to the variable is NULL, the function does nothing.
 * @remarks If the name or value of the variable is NULL, the function prints "(null)" instead.
 */
void	var_show(t_var *var);

/**
 * Frees the memory allocated for a variable.
 *
 * @param var A pointer to the variable to free.
 * @remarks If the pointer to the variable is NULL, the function does nothing.
 * @remarks The function frees the memory allocated for the variable's name and value using free(), and then frees the memory allocated for the variable itself.
 */
void	var_free(t_var *var);

#endif
