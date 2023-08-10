/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_and_condense_string.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 23:59:24 by lray              #+#    #+#             */
/*   Updated: 2023/08/10 00:51:20 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*condense_string(const char *input);

char	*trim_and_condense_string(const char *input)
{
	char	*trimmed_input;
	char	*condensed_input;

	trimmed_input = ft_strtrim(input, " ");
	condensed_input = condense_string(trimmed_input);
	free(trimmed_input);
	return (condensed_input);
}

/*
	//TODO: Handle malloc error
*/
static char	*condense_string(const char *input)
{
	size_t	input_len;
	char	*resp;
	size_t	consec_spaces;
	size_t	i;
	size_t	j;

	input_len = ft_strlen(input);
	resp = malloc(sizeof(char) * (input_len + 1));
	if (resp == NULL)
		return (NULL);
	resp = ft_memset(resp, '\0', input_len + 1);
	i = 0;
	j = 0;
	consec_spaces = 0;
	while (input[i] != '\0')
	{
		if (input[i] == ' ')
			consec_spaces++;
		else
			consec_spaces = 0;
		if (consec_spaces <= 1)
		{
			resp[j] = input[i];
			j++;
		}
		i++;
	}
	return (resp);
}
