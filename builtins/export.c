/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 01:51:07 by mflury            #+#    #+#             */
/*   Updated: 2023/10/14 03:23:50 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	export_show_alpha(t_lstvar *list);

int	builtin_export(char **argv, t_ctx *ctx)
{
	char	**list_names;
	int	i;

	i = 0;
	list_names = malloc(ctx->grpvar->global->num_elements + 1 * sizeof(char *));
	while (i < ctx->grpvar->global->num_elements)
	{
		list_names[i] = ctx->grpvar->global->array[i]->name;
		i++;
	}
	list_names[i] == NULL;
	if (!argv[1])
	{
		//put every name in a list:

		// sort list_name then show the corresponding ENV_VAR (alphabetical order).
		export_show_alpha(list_names);
	}
	else
	{
		// if (VALID_VAR)
			//	add VAR to ENV list.
	
	}
	return (0);
}

void	export_show_alpha(char **list)
{
	int i;
	int	j;
	int k;
    char *tmp_name;
	char *tmp_value;

	i = 0;
    while ((size_t)i < list->num_elements)
    {
		j = 0;
        while ((size_t)j < list->num_elements - i)
        {
			if(ft_strlen(list->array[j]->name) > ft_strlen(list->array[j + 1]->name))
				k = ft_strlen(list->array[j + 1]->name) - 1;
			else
				k = ft_strlen(list->array[j]->name) - 1;
            if (ft_strncmp(list->array[j]->name, list->array[j + 1]->name, k) > 0)
            {
                tmp_name = list->array[j]->name;
				tmp_value = list->array[j]->value;
                list->array[j]->name = list->array[j + 1]->name;
				list->array[j]->value = list->array[j + 1]->value;
                list->array[j + 1]->name = tmp_name;
				list->array[j + 1]->value = tmp_value;
            }
			j++;
        }
		i++;
    }
	lstvar_show(list);
}
