/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 22:06:58 by mflury            #+#    #+#             */
/*   Updated: 2023/10/01 00:23:43 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// for the moment we just have a simple "ctrl + c".

// TODO: ADD ctrl + d, ctrl + \ and all the variation modes.

// display a newline. (ctrl + c)
void	newline(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

// set the signals. (ctrl + c, ctrl + d, ctrl + \)
void	set_signals(char *input)
{
	(void) input;
	signal(SIGINT, newline);
}
