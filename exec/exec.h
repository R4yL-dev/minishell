/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 22:18:47 by lray              #+#    #+#             */
/*   Updated: 2023/10/29 00:25:34 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include <sys/wait.h>
# include <sys/stat.h>

int			exec(t_ctx *ctx);
int			exec_cmd(t_ctx *ctx, pid_t *pids);
int			exec_piped_cmd(t_ctx *ctx, int **pl, pid_t *pids);
t_env		*make_env(t_ctx *ctx, t_dyntree *root, int in_out[2]);
int			exec_env(t_ctx *ctx, pid_t *pid, int **pl, int nbr_p);
char		*get_cmd_path(char *cmd, t_grpvar *grpvar);
int			is_an_executable(char *path);
t_dynarrstr	*make_argv(t_dyntree *root);
int			open_file_rd(char *path);
int			open_file_wr(char *path);
int			open_file_wra(char *path);
int			get_infd(t_dyntree *root, t_ctx *ctx);
int			get_outfd(t_dyntree *root);
char		*make_heredoc(char *deli);

#endif
