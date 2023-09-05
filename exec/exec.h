/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 22:18:47 by lray              #+#    #+#             */
/*   Updated: 2023/08/22 16:52:35 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include <sys/wait.h>

int	exec(t_dyntree *root);

/**
 * @brief Opens all file descriptors for a command.
 *
 * This function opens all file descriptors for a command, based on the redirections
 * specified in the command tree. If any file descriptor cannot be opened, this function
 * returns 0. Otherwise, this function returns 1.
 *
 * @param root A pointer to the root of the command tree.
 * @param fd_in A pointer to the file descriptor for input redirection.
 * @param fd_out A pointer to the file descriptor for output redirection.
 * @return 1 if all file descriptors were opened successfully, or 0 if any error occurs.
 */
int	open_all_fd(t_dyntree *root, int *fd_in, int *fd_out);

/**
 * @brief Gets the path of a command.
 *
 * This function gets the path of a command by searching for it in the directories listed
 * in the `PATH` environment variable. If the command is already an executable file, this
 * function returns 1. Otherwise, this function searches for the command in each directory
 * listed in the `PATH` environment variable, and returns the path of the first executable
 * file found. If no executable file is found, this function returns 0.
 *
 * @param dynarr A pointer to the `t_dynarrstr` structure containing the command and its arguments.
 * @return 1 if the command is already an executable file, or the path of the first executable file found, or 0 if no executable file is found.
 */
int	get_cmd_path(t_dynarrstr *dynarr);

#endif
