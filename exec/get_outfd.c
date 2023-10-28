/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_outfd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 20:18:42 by lray              #+#    #+#             */
/*   Updated: 2023/10/29 00:25:50 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	get_outfd(t_dyntree *root)
{
	int		fd;
	size_t	i;

	fd = 1;
	if (root->type == TK_REDIRECTION && ft_strncmp(root->value, ">", 2) == 0)
		fd = open_file_wr(root->children[0]->value);
	else if (root->type == TK_REDIRECTION && \
	ft_strncmp(root->value, ">>", 3) == 0)
		fd = open_file_wra(root->children[0]->value);
	i = 0;
	while (i < root->numChildren)
	{
		if (root->children[i]->type == TK_REDIRECTION && \
		(ft_strncmp(root->children[i]->value, ">", 2) == 0 || \
		ft_strncmp(root->children[i]->value, ">>", 3) == 0))
		{
			if (fd > 2)
				close(fd);
			fd = get_outfd(root->children[i]);
		}
		++i;
	}
	return (fd);
}
