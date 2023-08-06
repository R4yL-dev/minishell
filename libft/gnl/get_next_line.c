/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:24:43 by lray              #+#    #+#             */
/*   Updated: 2023/02/14 11:57:03 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	read_from_fd(int fd, t_list **reserve);
static void	store_to_reserve(t_list **reserve, char *buf, int nbr_char_read);
static void	get_line(t_list *reserve, char **line);
static void	clean_reserve(t_list **reserve);

char	*get_next_line(int fd)
{
	static t_list	*reserve = NULL;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	read_from_fd(fd, &reserve);
	if (reserve == NULL)
		return (NULL);
	get_line(reserve, &line);
	clean_reserve(&reserve);
	if (line[0] == '\0')
	{
		free_all(reserve);
		reserve = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}

static void	read_from_fd(int fd, t_list **reserve)
{
	char	*buf;
	int		nbr_char_read;

	nbr_char_read = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (!has_newline(*reserve) && nbr_char_read != 0)
	{
		if (buf == NULL)
			return ;
		nbr_char_read = read(fd, buf, BUFFER_SIZE);
		if ((*reserve == NULL && nbr_char_read == 0) || nbr_char_read == -1)
		{
			free(buf);
			if (nbr_char_read == -1)
				free_all(*reserve);
			*reserve = NULL;
			return ;
		}
		buf[nbr_char_read] = '\0';
		store_to_reserve(reserve, buf, nbr_char_read);
	}
	free(buf);
}

static void	store_to_reserve(t_list **reserve, char *buf, int nbr_char_read)
{
	t_list	*last;
	t_list	*new;
	int		i;

	new = malloc(sizeof(t_list));
	new->content = malloc(sizeof(char) * (nbr_char_read + 1));
	if (new == NULL || new->content == NULL)
		return ;
	new->next = NULL;
	i = 0;
	while (buf[i] && i < nbr_char_read)
	{
		new->content[i] = buf[i];
		i++;
	}
	new->content[i] = '\0';
	if (*reserve == NULL)
		*reserve = new;
	else
	{
		last = get_last_node(*reserve);
		last->next = new;
	}
}

static void	get_line(t_list *reserve, char **line)
{
	int	i;
	int	j;

	if (reserve == NULL)
		return ;
	make_line(line, reserve);
	if (*line == NULL)
		return ;
	j = 0;
	while (reserve)
	{
		i = 0;
		while (reserve->content[i])
		{
			if (reserve->content[i] == '\n')
			{
				(*line)[j++] = reserve->content[i];
				break ;
			}
			(*line)[j++] = reserve->content[i++];
		}
		reserve = reserve->next;
	}
	(*line)[j] = '\0';
}

static void	clean_reserve(t_list **reserve)
{
	t_list	*last;
	t_list	*new;
	int		i;

	new = malloc(sizeof(t_list));
	if (reserve == NULL || new == NULL)
		return ;
	new->next = NULL;
	last = get_last_node(*reserve);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content[i] == '\n')
		i++;
	new->content = get_content(last, i);
	if (new->content == NULL)
		return ;
	free_all(*reserve);
	*reserve = new;
}
