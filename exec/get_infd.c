/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 20:18:42 by lray              #+#    #+#             */
/*   Updated: 2023/10/04 01:10:28 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	get_infd(t_dyntree *root)
{
	int	fd;
	size_t	i_child;

	fd = 0;
	if (root->type == TK_REDIRECTION && root->value[0] == '<' && ft_strlen(root->value) == 1)
		fd = open_file_rd(root->children[0]->value);
	i_child = 0;
	while (i_child < root->numChildren)
	{
		if (root->children[i_child]->type == TK_REDIRECTION && root->children[i_child]->value[0] == '<' && ft_strlen(root->children[i_child]->value) == 1)
		{
			if (fd > 2)
				close(fd);
			fd = get_infd(root->children[i_child]);
		}
		++i_child;
	}
	return (fd);
}
