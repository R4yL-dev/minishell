/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 22:06:58 by mflury            #+#    #+#             */
/*   Updated: 2023/10/04 00:55:27 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// for the moment we just have "ctrl+c" and "ctrl+\", but not heredoc mode.

// ctrl+d isnt a signal but a macro that send EOF and works only on an empty line.
// its treated on the main.

// TODO: ADD the heredoc variation modes.

// display a newline. (ctrl+c)
void	newline(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

// set the signals. (ctrl+c = newline, ctrl+\ = ignored)
void	set_signals(char *input)
{
	(void) input;
	signal(SIGINT, newline);
	signal(SIGQUIT, SIG_IGN);
}
