/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:31:46 by lray              #+#    #+#             */
/*   Updated: 2023/08/10 13:32:40 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	db_show_tklist(t_tklist *tklist)
{
	t_tklist	*tmp;

	tmp = tklist;
	while (tmp)
	{
		printf("value: %s\n", tmp->value);
		printf("type: %d\n", tmp->type);
		tmp = tmp->next;
	}
}
