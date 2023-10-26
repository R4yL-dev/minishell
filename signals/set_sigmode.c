/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sigmode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:39:24 by lray              #+#    #+#             */
/*   Updated: 2023/10/24 17:01:38 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	set_sigmode(sigset_t *sigset, int mode)
{
	struct sigaction	sa;

	if (mode == SIGMODE_NORMAL)
	{
		g_in_heredoc = 0;
		sigemptyset(sigset);
		sigaddset(sigset, SIGINT);
		sa.sa_handler = handle_sigint;
		sa.sa_mask = *sigset;
		sa.sa_flags = 0;
		sigaction(SIGINT, &sa, NULL);
		sigaddset(sigset, SIGQUIT);
		sa.sa_handler = handle_sigquit;
		sa.sa_mask = *sigset;
		sa.sa_flags = 0;
		sigaction(SIGQUIT, &sa, NULL);
	}
	else if (mode == SIGMODE_HEREDOC)
	{
		g_in_heredoc = 1;
		sigemptyset(sigset);
		sigaddset(sigset, SIGINT);
		sa.sa_handler = handle_sigint_heredoc;
		sa.sa_mask = *sigset;
		sa.sa_flags = 0;
		sigaction(SIGINT, &sa, NULL);
		sigaddset(sigset, SIGQUIT);
		sa.sa_handler = handle_sigquit_heredoc;
		sa.sa_mask = *sigset;
		sa.sa_flags = 0;
		sigaction(SIGQUIT, &sa, NULL);
	}
	else
	{
		ft_puterror("Unknow mode");
		return (0);
	}
	return (1);
}
