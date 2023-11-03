/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 22:03:07 by mflury            #+#    #+#             */
/*   Updated: 2023/11/02 16:23:57 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

# include "../minishell.h"

# include <signal.h>
# include <sys/ioctl.h>

# define SIGMODE_DEFAULT 0
# define SIGMODE_HEREDOC 1
# define SIGMODE_CMD 2

void	sig_update(int sig);

void	handle_sigint(int sig);
void	handle_sigint_heredoc(int sig);
void	handle_sigquit(int sig);
void	handle_sigquit_heredoc(int sig);
void	handle_sigint_cmd(int sig);

#endif
