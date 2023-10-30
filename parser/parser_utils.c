/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:57:44 by lray              #+#    #+#             */
/*   Updated: 2023/10/30 13:46:05 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	has_token_type(t_dyntklist *tklist, int token_type)
{
	int	pos;

	if (tklist == NULL || tklist->array == NULL || token_type < 0)
		return (-1);
	pos = 0;
	while (tklist->array[pos])
	{
		if (tklist->array[pos]->type == token_type)
			return (pos);
		pos++;
	}
	return (-1);
}
