/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sigquit_heredoc.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:14:49 by lray              #+#    #+#             */
/*   Updated: 2023/11/02 16:50:42 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	handle_sigquit_heredoc(int sig)
{
	(void) sig;
	g_code = 131;
	ft_putstr_fd("Quit: 3\n", 1);
	rl_redisplay();
}
