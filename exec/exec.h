/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 22:18:47 by lray              #+#    #+#             */
/*   Updated: 2023/09/26 21:02:12 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include <sys/wait.h>

int	exec(t_dyntree *root, t_grpvar *grpvar);

int	open_all_fd(t_dyntree *root, int *fd_in, int *fd_out);

int	get_cmd_path(t_dynarrstr *dynarr, t_grpvar *grpvar);

#endif
