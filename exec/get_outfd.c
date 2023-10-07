/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_outfd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 20:18:42 by lray              #+#    #+#             */
/*   Updated: 2023/10/07 14:09:57 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	get_outfd(t_dyntree *root)
{
	int	fd;
	size_t	i_child;

	fd = 1;
	if (root->type == TK_REDIRECTION && root->value[0] == '>' && ft_strlen(root->value) == 1)
		fd = open_file_wr(root->children[0]->value);
	else if (root->type == TK_REDIRECTION && ft_strlen(root->value) == 2 && ft_strncmp(root->value, ">>", 2) == 0)
		fd = open_file_wra(root->children[0]->value);
	i_child = 0;
	while (i_child < root->numChildren)
	{
		if (root->children[i_child]->type == TK_REDIRECTION && root->children[i_child]->value[0] == '>')
		{
			if (fd > 2)
				close(fd);
			fd = get_outfd(root->children[i_child]);
		}
		else if (root->children[i_child]->type == TK_REDIRECTION && ft_strlen(root->children[i_child]->value) == 2 && ft_strncmp(root->children[i_child]->value, ">>", 2) == 0)
		{
			if (fd > 2)
				close(fd);
			fd = get_outfd(root->children[i_child]);
		}
		++i_child;
	}
	return (fd);
}
