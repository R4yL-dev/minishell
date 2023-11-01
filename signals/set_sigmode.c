/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sigmode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:39:24 by lray              #+#    #+#             */
/*   Updated: 2023/10/31 20:47:12 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	set_normal_mode(sigset_t *sigset);
static void	set_heredoc_mode(sigset_t *sigset);

int	set_sigmode(sigset_t *sigset, int mode)
{
	if (mode == SIGMODE_NORMAL)
		set_normal_mode(sigset);
	else if (mode == SIGMODE_HEREDOC)
		set_heredoc_mode(sigset);
	else
	{
		ft_puterror("Unknow mode");
		return (0);
	}
	return (1);
}

static void	set_normal_mode(sigset_t *sigset)
{
	struct sigaction	sa;

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

static void	set_heredoc_mode(sigset_t *sigset)
{
	struct sigaction	sa;

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
