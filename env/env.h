/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 21:46:59 by mflury            #+#    #+#             */
/*   Updated: 2023/08/17 03:18:28 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

//        ~~~~~   get_path.c   ~~~~~

// put all the possible paths for binaries from $PATH in a tab,
// return NULL if $PATH is not set, else return the tab.
char	**get_path(t_grpvar *grpvar);

// free the tab for paths tab. PROBABLY A DUPLICATE FUNCTION!
void 	free_path(char **paths);

//        ~~~~~   echo.c   ~~~~~

// print the arguments in the dynarrstr,
// if the first argument is "-n", don't print a new line.
// interpret $VAR in the arguments.
// void	echo(t_dynarrstr *dynarr);

// int is_only_slash(char *str);
// int is_slash(char c);

#endif
