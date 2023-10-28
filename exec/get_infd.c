/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 20:18:42 by lray              #+#    #+#             */
/*   Updated: 2023/10/29 00:25:45 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	run_heredoc(t_ctx *ctx, t_dyntree	*root);

int	get_infd(t_dyntree *root, t_ctx *ctx)
{
	int		fd;
	size_t	i;

	fd = 0;
	if (root->type == TK_REDIRECTION)
	{
		if (root->type == TK_REDIRECTION && \
		ft_strncmp(root->value, "<<", 3) == 0)
			run_heredoc(ctx, root);
		fd = open_file_rd(root->children[0]->value);
	}
	i = 0;
	while (i < root->numChildren)
	{
		if (root->children[i]->type == TK_REDIRECTION && \
		(ft_strncmp(root->children[i]->value, "<", 2) == 0 || \
		ft_strncmp(root->children[i]->value, "<<", 3) == 0))
		{
			if (fd > 2)
				close(fd);
			fd = get_infd(root->children[i], ctx);
		}
		++i;
	}
	return (fd);
}

static void	run_heredoc(t_ctx *ctx, t_dyntree	*root)
{
	char	*filename;

	filename = NULL;
	set_sigmode(&ctx->sigset, SIGMODE_HEREDOC);
	filename = make_heredoc(root->children[0]->value);
	free(root->children[0]->value);
	root->children[0]->value = filename;
	set_sigmode(&ctx->sigset, SIGMODE_NORMAL);
}
