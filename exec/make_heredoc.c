/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:11:04 by lray              #+#    #+#             */
/*   Updated: 2023/11/02 13:17:00 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*make_filename(void);
static int	get_randnum(void);
static void	put_to_fd(int fd, char *input);

char	*make_heredoc(char *deli)
{
	char	*filename;
	int		fd;
	char	*input;

	filename = make_filename();
	fd = open_file_wr(filename);
	while (1)
	{
		input = readline("> ");
		if (input == NULL)
		{
			ft_puterror("\nminishell: warn: here-doc delimited by end-of-file");
			free(input);
			break ;
		}
		if (g_code == 130 || ft_strncmp(deli, input, ft_strlen(deli) + 1) == 0)
		{
			free(input);
			break ;
		}
		put_to_fd(fd, input);
		free(input);
	}
	close(fd);
	return (filename);
}

static char	*make_filename(void)
{
	char	*res;
	int		rand;
	char	*rand_str;

	rand_str = NULL;
	rand = get_randnum();
	rand_str = ft_itoa(rand);
	res = malloc(sizeof(char) * (ft_strlen(rand_str) + 15));
	if (!res)
	{
		ft_puterror("Malloc failed");
		return (NULL);
	}
	ft_strlcpy(res, "/tmp/minishell", 15);
	ft_strlcat(res, rand_str, ft_strlen(rand_str) + 15);
	free(rand_str);
	return (res);
}

static int	get_randnum(void)
{
	int	res;
	int	fd;

	res = 0;
	fd = open("/dev/urandom", O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (0);
	}
	if (read(fd, &res, sizeof(res)) != sizeof(res))
	{
		perror("read");
		return (0);
	}
	if (close(fd) == -1)
	{
		perror("close");
		return (0);
	}
	res = ft_abs(res);
	return (res);
}

static void	put_to_fd(int fd, char *input)
{
	write(fd, input, ft_strlen(input));
	write(fd, "\n", 1);
}
