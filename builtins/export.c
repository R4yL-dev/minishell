/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 01:51:07 by mflury            #+#    #+#             */
/*   Updated: 2023/10/16 14:58:39 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// SEGV ON LINE 43 FML I CANT MAKE IT WORK T_T...

int	builtin_export(char **argv, t_ctx *ctx)
{
	(void)argv;
	char	**list_names;
	char	tmp[100];
	int		i;
	int		j;
	i = 0;
	// make a list of all var names: (seems ok)
	list_names = malloc(ctx->grpvar->global->num_elements * sizeof(char *));
	while (i < (int)ctx->grpvar->global->num_elements - 1)
	{
		list_names[i] = malloc(100 * sizeof(char));
		ft_bzero(list_names[i], 100);
		ft_strlcpy(list_names[i], ctx->grpvar->global->array[i]->name, ft_strlen(ctx->grpvar->global->array[i]->name) + 1);
		i++;
	}
	// sort name in alpha order: (idk if it works cant make it run)
	i = 0;
	 while (i < (int)ctx->grpvar->global->num_elements)
    {
		j = 0;
        while (j + 1 < (int)ctx->grpvar->global->num_elements - 1)
        {
			printf("J: %s\nJ + 1: %s\n", list_names[j], list_names[j + 1]);
            if (ft_strncmp(list_names[j], list_names[j + 1], ft_strlen(list_names[j]) + ft_strlen(list_names[j + 1])+ 1) > 0)
            {
                ft_strlcpy(tmp, list_names[j], ft_strlen(list_names[j]));
				ft_strlcpy(list_names[j], list_names[j + 1], ft_strlen(list_names[j + 1]));
                list_names[j] = list_names[j + 1];
                ft_strlcpy(list_names[j + 1], tmp, ft_strlen(tmp));
				list_names[j + 1] = tmp;
            }
			j++;
        }
		i++;
    }
	// check sorted list:
	i = 0;
	while (i < (int)ctx->grpvar->global->num_elements - 1)
	{
		printf("%s\n", list_names[i]);
		i++;
	}
	// call all the var one by one from list:
	i = 0;
	j = 0;
	while (i < (int)ctx->grpvar->global->num_elements - 1)
	{
		j = (int)grpvar_has(ctx->grpvar, GRPVAR_GLOBAL, list_names[i]);
		printf("%s=%s\n", ctx->grpvar->global->array[j]->name, ctx->grpvar->global->array[j]->value);
		i++;
	}
	return (0);
}






// void	export_show_alpha(t_lstvar *list);

// int	builtin_export(char **argv, t_ctx *ctx)
// {
// 	char	**list_names;
// 	int	i;

// 	i = 0;
// 	list_names = malloc(ctx->grpvar->global->num_elements + 1 * sizeof(char *));
// 	while (i < ctx->grpvar->global->num_elements)
// 	{
// 		list_names[i] = ctx->grpvar->global->array[i]->name;
// 		i++;
// 	}
// 	list_names[i] == NULL;
// 	if (!argv[1])
// 	{
// 		//put every name in a list:

// 		// sort list_name then show the corresponding ENV_VAR (alphabetical order).
// 		export_show_alpha(list_names, ctx);
// 	}
// 	else
// 	{
// 		// if (VALID_VAR)
// 			//	add VAR to ENV list.
	
// 	}
// 	return (0);
// }

// void	export_show_alpha(char **list, t_ctx *ctx)
// {
// 	int i;
// 	int	j;
// 	int k;
//     char *tmp_name;
// 	char *tmp_value;

// 	i = 0;
//     while ((size_t)i < list->num_elements)
//     {
// 		j = 0;
//         while ((size_t)j < list->num_elements - i)
//         {
// 			if(ft_strlen(list->array[j]->name) > ft_strlen(list->array[j + 1]->name))
// 				k = ft_strlen(list->array[j + 1]->name) - 1;
// 			else
// 				k = ft_strlen(list->array[j]->name) - 1;
//             if (ft_strncmp(list->array[j]->name, list->array[j + 1]->name, k - 1) > 0)
//             {
//                 tmp_name = list->array[j]->name;
// 				tmp_value = list->array[j]->value;
//                 list->array[j]->name = list->array[j + 1]->name;
// 				list->array[j]->value = list->array[j + 1]->value;
//                 list->array[j + 1]->name = tmp_name;
// 				list->array[j + 1]->value = tmp_value;
//             }
// 			j++;
//         }
// 		i++;
//     }
// 	lstvar_show(list);
// }
