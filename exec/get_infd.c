/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 20:18:42 by lray              #+#    #+#             */
/*   Updated: 2023/10/23 22:12:43 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	get_infd(t_dyntree *root, t_ctx *ctx)
{
	int		fd;
	size_t	i_child;
	char	*filename;

	filename = NULL;
	fd = 0;
	if (root->type == TK_REDIRECTION)
	{
		if (root->type == TK_REDIRECTION && ft_strncmp(root->value, "<<\0", 3) == 0)
		{
			set_sigmode(&ctx->sigset, SIGMODE_HEREDOC);
			filename = make_heredoc(root->children[0]->value);
			free(root->children[0]->value);
			root->children[0]->value = filename;
			set_sigmode(&ctx->sigset, SIGMODE_NORMAL);
		}
		fd = open_file_rd(root->children[0]->value);
	}
	i_child = 0;
	while (i_child < root->numChildren)
	{
		if (root->children[i_child]->type == TK_REDIRECTION && (ft_strncmp(root->children[i_child]->value, "<\0", 2) == 0 || ft_strncmp(root->children[i_child]->value, "<<\0", 3) == 0))
		{
			if (fd > 2)
				close(fd);
			fd = get_infd(root->children[i_child], ctx);
		}
		++i_child;
	}
	return (fd);
}
