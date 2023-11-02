/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:48:12 by lray              #+#    #+#             */
/*   Updated: 2023/11/02 16:28:59 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	sig_update(int sig)
{
	if (sig == SIGMODE_DEFAULT)
	{
		signal(SIGINT, handle_sigint);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (sig == SIGMODE_HEREDOC)
	{
		signal(SIGINT, handle_sigint_heredoc);
		signal(SIGQUIT, handle_sigquit_heredoc);
	}
	else if (sig == SIGMODE_CMD)
	{
		signal(SIGINT, handle_sigint_cmd);
		signal(SIGQUIT, SIG_IGN);
	}
}
