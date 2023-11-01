/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:55:56 by lray              #+#    #+#             */
/*   Updated: 2023/10/30 18:05:31 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	process_quotes(t_dyntree *root, size_t *i, char *quote);

int	delete_quotes(t_dyntree *root)
{
	size_t	i_child;
	size_t	i_str;
	char	quote;

	quote = 0;
	if (root->type == TK_COMMAND || \
	root->type == TK_ARGUMENT || root->type == TK_FILE)
	{
		i_str = 0;
		while (root->value[i_str] != '\0')
		{
			if (is_quote(root->value[i_str]))
				process_quotes(root, &i_str, &quote);
			++i_str;
		}
	}
	i_child = 0;
	while (i_child < root->num_children)
		delete_quotes(root->children[i_child++]);
	return (1);
}

static void	process_quotes(t_dyntree *root, size_t *i, char *quote)
{
	if (*quote == 0)
	{
		*quote = root->value[*i];
		ft_memmove(root->value + *i, \
		root->value + *i + 1, ft_strlen(root->value + *i));
		(*i)--;
	}
	else if (root->value[*i] == *quote)
	{
		*quote = 0;
		ft_memmove(root->value + *i, \
		root->value + *i + 1, ft_strlen(root->value + *i));
		(*i)--;
	}
}
