/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:49:07 by lray              #+#    #+#             */
/*   Updated: 2023/10/21 16:37:38 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	*env_new(void)
{
	t_env *new;

	new = malloc(sizeof(t_env) * 1);
	if (new == NULL)
	{
		ft_puterror("Malloc failed");
		return (NULL);
	}
	new->type = -1;
	new->path = NULL;
	new->args = NULL;
	new->fd_in = STDIN_FILENO;
	new->fd_out = STDOUT_FILENO;
	new->pipe_in = -1;
	new->pipe_out = -1;
	return (new);
}

void	env_show(t_env *env)
{
	if (env)
	{
		printf("env type : %d\n", env->type);
		printf("env path : %s\n", env->path);
		if (env->args)
		{
			printf("env args :\n");
			arr_show(env->args);
		}
		printf("env fd_in : %d\n", env->fd_in);
		printf("env fd_out : %d\n", env->fd_out);
		printf("env pipe_in : %d\n", env->pipe_in);
		printf("env pipe_out : %d\n", env->pipe_out);
	}
}

void	env_free(t_env *env)
{
	if (env != NULL)
	{
		if (env->path != NULL)
		{
			free(env->path);
			env->path = NULL;
		}
		if (env->args != NULL)
		{
			free_split(env->args);
			env->args = NULL;
		}
		if (env->fd_in > 2)
			close(env->fd_in);
		if (env->fd_out > 2)
			close(env->fd_out);
		if (env->pipe_in > 2)
			close(env->pipe_in);
		if (env->pipe_out > 2)
			close(env->pipe_out);
		free(env);
		env = NULL;
	}
}
