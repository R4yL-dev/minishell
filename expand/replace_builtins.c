/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_builtins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:17:17 by lray              #+#    #+#             */
/*   Updated: 2023/10/02 16:08:33 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static DIR	*open_builtins_dir(void);
static char	*make_filename(char	*value);
static int	search_builtins(DIR *dir, char	*filename);

int	replace_builtins(t_dyntree *root)
{
	size_t	i_child;
	DIR		*dir;
	char	*filename;

	filename = NULL;
	if (root->type == TK_COMMAND)
	{
		dir = open_builtins_dir();
		if (!dir)
			return (0);
		filename = make_filename(root->value);
		if (!filename)
		{
			closedir(dir);
			return (0);
		}
		if (search_builtins(dir, filename))
			root->type = TK_BUILTINS;
		free(filename);
		closedir(dir);
	}
	i_child = 0;
	while (i_child < root->numChildren)
	{
		if (!replace_builtins(root->children[i_child++]))
			return (0);
	}
	return (1);
}

static DIR	*open_builtins_dir(void)
{
	DIR	*dir;

	dir = opendir("builtins");
	if (!dir)
	{
		perror("minishell : builtins");
		return (NULL);
	}
	return (dir);
}

static char	*make_filename(char	*value)
{
	char	*filename;

	if (!value)
		return (NULL);
	filename = malloc(sizeof(char) * ft_strlen(value) + 3);
	if (!filename)
	{
		ft_puterror("Malloc failed");
		return (NULL);
	}
	ft_strlcpy(filename, value, ft_strlen(value) + 1);
	ft_strlcat(filename, ".c", ft_strlen(value) + 3);
	return (filename);
}

static int	search_builtins(DIR *dir, char	*filename)
{
	struct dirent	*entry;
	(void)	filename;

	entry = readdir(dir);
	while (entry != NULL)
	{
		if (entry->d_type == DT_REG)
		{
			if (ft_strncmp(filename, entry->d_name, ft_strlen(filename)) == 0)
				return (1);
		}
		entry = readdir(dir);
	}
	return (0);
}
