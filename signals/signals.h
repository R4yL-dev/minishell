/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 22:03:07 by mflury            #+#    #+#             */
/*   Updated: 2023/10/31 20:48:39 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

# include "../minishell.h"

# include <signal.h>
# include <sys/ioctl.h>

# define SIGMODE_NORMAL 0
# define SIGMODE_HEREDOC 1

int		set_sigmode(sigset_t *sigset, int mode);

void	handle_sigint(int sig);
void	handle_sigint_heredoc(int sig);
void	handle_sigquit(int sig);
void	handle_sigquit_heredoc(int sig);

#endif
