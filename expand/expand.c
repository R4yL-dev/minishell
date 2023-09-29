/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:19:55 by lray              #+#    #+#             */
/*   Updated: 2023/09/29 18:11:05 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	replace_var(t_dyntree *root, t_grpvar *grpvar);
static int	is_var(t_dyntree *root);
static int	valide_tree(t_dyntree *root);
static char	*add_char_to_string(char *str, char c);

t_dyntree	*expand(t_dyntree *root, t_grpvar *grpvar)
{
	if (!replace_var(root, grpvar))
		return (NULL);
	if (!valide_tree(root))
		return (NULL);
	return (root);
}

static int	replace_var(t_dyntree *root, t_grpvar *grpvar)
{
	size_t	i_str;
	size_t	i_child;
	char	*varname;
	size_t	pos;
	char	*new_value;


	if (!root || !grpvar)
		return (0);
	if (is_var(root))
	{
		i_str = 1;
		varname = malloc(sizeof(char) * 1);
		if (!varname)
		{
			ft_puterror("Malloc failed");
			return (0);
		}
		varname[0] = '\0';
		if (root->value[i_str] != '\0' || ft_isalnum(root->value[i_str]))
		{
			while (root->value[i_str] != '\0' && ft_isalnum(root->value[i_str]))
			{
				varname = add_char_to_string(varname, root->value[i_str]);
				i_str++;
			}
			pos = grpvar_has(grpvar, GRPVAR_GLOBAL, varname);
			if ((int)pos >= 0)
			{
				int	len_one = (int)ft_strlen(root->value + i_str);
				int len_two = (int)ft_strlen(grpvar->global->array[pos]->value);

				new_value = malloc(sizeof(char) * (len_one + len_two) + 1);
				ft_strlcpy(new_value, grpvar->global->array[pos]->value, len_two + 1);
				ft_strlcat(new_value, root->value + i_str, len_one + len_two + 1);
			}
			else
			{
				new_value = malloc(sizeof(char) * ft_strlen(root->value + i_str) + 1);
				ft_strlcpy(new_value, root->value + i_str, ft_strlen(root->value));
			}
			free(root->value);
			root->value = new_value;
		}
	}
	i_child = 0;
	while (i_child < root->numChildren)
		if (!replace_var(root->children[i_child++], grpvar))
			return (0);
	return (1);
}

static int	is_var(t_dyntree *root)
{
	if (root->value[0] == '$')
		return (1);
	return (0);
}

static int	valide_tree(t_dyntree *root)
{
	size_t	i;

	if (!root)
		return (0);
	if (root->type == TK_FILE)
	{
		if (root->value[0] == '\0')
		{
			ft_puterror("ambiguous redirect");
			return (0);
		}
	}
	if (root->type == TK_COMMAND)
	{
		if (root->value[0] == '\0')
			return (0);
	}
	i = 0;
	while (i < root->numChildren)
	{
		if (!valide_tree(root->children[i++]))
			return (0);
	}
	return (1);
}

static char	*add_char_to_string(char *str, char c)
{
	size_t	len;

	len = ft_strlen(str) + 1;
	str = ft_realloc(str, len, len + 1);
	if (!str)
		return (NULL);
	str[len - 1] = c;
	str[len] = '\0';
	return (str);
}
