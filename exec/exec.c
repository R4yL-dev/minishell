/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 22:19:41 by lray              #+#    #+#             */
/*   Updated: 2023/08/19 17:22:37 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static t_dynarrstr	*make_argv(t_dyntree *root);
static int			run_cmd(int fd_in, int fd_out, char **argv);
static void			clean_mem(t_dynarrstr *dynarr, int fd_in, int fd_out);

int	exec(t_dyntree *root)
{
	t_dynarrstr	*dynarr;
	int			fd_in;
	int			fd_out;

	fd_in = STDIN_FILENO;
	fd_out = STDOUT_FILENO;
	if (open_all_fd(root, &fd_in, &fd_out) == 0)
		return (0);
	if (is_redirect(root->value) == 1)
		return (0);
	dynarr = make_argv(root);
	if (dynarr == NULL)
		return (0);
	if (get_cmd_path(dynarr) == 0)
	{
		ft_puterror("Command not found");
		dynarrstr_free(dynarr);
		return (0);
	}
	if (run_cmd(fd_in, fd_out, dynarr->array) == 0)
	{
		dynarrstr_free(dynarr);
		return (0);
	}
	clean_mem(dynarr, fd_in, fd_out);
	return (1);
}

static t_dynarrstr	*make_argv(t_dyntree *root)
{
	t_dynarrstr	*dynarr;
	size_t		i;

	dynarr = NULL;
	dynarr = dynarrstr_init(dynarr);
	if (dynarr == NULL)
		return (NULL);
	if (root && root->value)
	{
		if (dynarrstr_add(dynarr, root->value) == 0)
			return (NULL);
		i = 0;
		while (i < root->numChildren)
		{
			if (root->children[i]->type == TK_ARGUMENT)
			{
				if (dynarrstr_add(dynarr, root->children[i]->value) == 0)
					return (NULL);
			}
			i++;
		}
	}
	else
		return (NULL);
	return (dynarr);
}

static int	run_cmd(int fd_in, int fd_out, char **argv)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		ft_puterror("Fork error.\n");
		return (0);
	}
	if (pid == 0)
	{
		dup2(fd_in, STDIN_FILENO);
		dup2(fd_out, STDOUT_FILENO);
		execve(argv[0], argv, NULL);
	}
	else
		wait(NULL);
	return (1);
}

static void	clean_mem(t_dynarrstr *dynarr, int fd_in, int fd_out)
{
	dynarrstr_free(dynarr);
	if (fd_in != STDIN_FILENO)
		close(fd_in);
	if (fd_out != STDOUT_FILENO)
		close(fd_out);
}
