/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dyntklist_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:02:57 by lray              #+#    #+#             */
/*   Updated: 2023/10/30 11:51:54 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int			count_pipes(t_dyntklist *tklist);
static t_dyntklist	**alloc_res(t_dyntklist **res, int nbr_list);
static t_dyntklist	**set_res(t_dyntklist **res, t_dyntklist *tklist);

t_dyntklist	**dyntklist_split(t_dyntklist *tklist)
{
	int			num_pipes;
	t_dyntklist	**res;

	res = NULL;
	num_pipes = count_pipes(tklist);
	if (num_pipes > 0)
	{
		res = alloc_res(res, num_pipes + 1);
		if (!res)
			return (NULL);
		res = set_res(res, tklist);
	}
	return (res);
}

void	dyntklist_split_free(t_dyntklist **arr_tklist)
{
	int	i_arr;

	i_arr = 0;
	while (arr_tklist[i_arr])
	{
		dyntklist_free(arr_tklist[i_arr]);
		arr_tklist[i_arr] = NULL;
		++i_arr;
	}
	free(arr_tklist);
	arr_tklist = NULL;
}

static int	count_pipes(t_dyntklist *tklist)
{
	int	i;
	int	num_pipes;

	num_pipes = 0;
	i = 0;
	while (i < (int)tklist->size)
	{
		if (tklist->array[i]->type == TK_PIPE)
			++num_pipes;
		++i;
	}
	return (num_pipes);
}

static t_dyntklist	**alloc_res(t_dyntklist **res, int nbr_list)
{
	int	i;

	i = 0;
	if (res || nbr_list < 2)
		return (NULL);
	res = malloc(sizeof(t_dyntklist *) * (nbr_list + 1));
	if (!res)
	{
		ft_puterror("Malloc failed");
		return (NULL);
	}
	while (i < nbr_list)
	{
		res[i] = NULL;
		res[i] = dyntklist_init(res[i]);
		++i;
	}
	res[i] = NULL;
	return (res);
}

static t_dyntklist	**set_res(t_dyntklist **res, t_dyntklist *tklist)
{
	int	i_res;
	int	i_tklist;

	i_res = 0;
	i_tklist = 0;
	while (res[i_res])
	{
		while (i_tklist < (int)tklist->size)
		{
			if (tklist->array[i_tklist]->type != TK_PIPE)
				dyntklist_add(res[i_res], tklist->array[i_tklist]->type, \
				tklist->array[i_tklist]->value);
			else
			{
				++i_tklist;
				break ;
			}
			++i_tklist;
		}
		++i_res;
	}
	return (res);
}
