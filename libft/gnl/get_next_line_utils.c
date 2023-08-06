/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:24:48 by lray              #+#    #+#             */
/*   Updated: 2023/02/14 11:52:30 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	has_newline(t_list *reserve)
{
	int		i;

	if (reserve == NULL)
		return (0);
	i = 0;
	if (reserve == NULL)
		return (0);
	while (reserve->next != NULL)
		reserve = reserve->next;
	while (reserve->content[i])
	{
		if (reserve->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	free_all(t_list *reserve)
{
	t_list	*current;
	t_list	*next;

	current = reserve;
	while (current)
	{
		free(current->content);
		next = current->next;
		free(current);
		current = next;
	}
}

t_list	*get_last_node(t_list *reserve)
{
	if (reserve == NULL)
		return (NULL);
	while (reserve->next != NULL)
		reserve = reserve->next;
	return (reserve);
}

void	make_line(char **line, t_list *reserve)
{
	int	i;
	int	j;

	j = 0;
	while (reserve)
	{
		i = 0;
		while (reserve->content[i])
		{
			if (reserve->content[i] == '\n')
			{
				j++;
				break ;
			}
			i++;
			j++;
		}
		reserve = reserve->next;
	}
	*line = malloc(sizeof(char) * (j + 1));
}

char	*get_content(t_list *last, int i)
{
	char	*resp;
	int		j;
	int		len;

	len = 0;
	while (last->content[len])
		len++;
	resp = malloc(sizeof(char) * (len - i + 1));
	if (resp == NULL)
		return (NULL);
	j = 0;
	while (last->content[i])
		resp[j++] = last->content[i++];
	resp[j] = '\0';
	return (resp);
}
