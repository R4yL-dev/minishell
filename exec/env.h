/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:48:33 by lray              #+#    #+#             */
/*   Updated: 2023/10/21 16:37:54 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

typedef struct s_env
{
	int					type;
	char				*path;
	char				**args;
	int					fd_in;
	int					fd_out;
	int					pipe_in;
	int					pipe_out;
}	t_env;

t_env	*env_new(void);

void	env_show(t_env *head);

void	env_free(t_env *node);

#endif
