/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 19:49:33 by lray              #+#    #+#             */
/*   Updated: 2023/09/29 19:54:55 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	is_var(t_dyntree *root);
static char	*init_varname(char *varname);
static char	*make_varname(char *varname, t_dyntree *root, size_t *i_str);
static int	update_root_value(t_dyntree *root, t_grpvar *grpvar, size_t i_str, size_t i_var);
static int	update_root_null(t_dyntree *root, size_t i_str);

int	replace_var(t_dyntree *root, t_grpvar *grpvar)
{
	size_t	i_str;
	size_t	i_var;
	size_t	i_child;
	char	*varname;

	if (is_var(root))
	{
		varname = NULL;
		varname = init_varname(varname);
		i_str = 1;
		if (root->value[i_str] != '\0' || ft_isalnum(root->value[i_str]))
		{
			varname = make_varname(varname, root, &i_str);
			i_var = grpvar_has(grpvar, GRPVAR_GLOBAL, varname);
			if ((int)i_var >= 0)
				update_root_value(root, grpvar, i_str, i_var);
			else
				update_root_null(root, i_str);
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

static char	*init_varname(char *varname)
{
	varname = malloc(sizeof(char) * 1);
	if (!varname)
	{
		ft_puterror("Malloc failed");
		return (NULL);
	}
	varname[0] = '\0';
	return (varname);
}

static char	*make_varname(char *varname, t_dyntree *root, size_t *i_str)
{
	while (root->value[*i_str] != '\0' && ft_isalnum(root->value[*i_str]))
	{
		varname = add_char_to_string(varname, root->value[*i_str]);
		if (!varname)
			return (NULL);
		(*i_str)++;
	}
	return (varname);
}

static int	update_root_value(t_dyntree *root, t_grpvar *grpvar, size_t i_str, size_t i_var)
{
	int		len_endstr;
	int		len_var;
	char	*new_value;

	if (!root || !grpvar)
		return (0);
	len_endstr = (int)ft_strlen(root->value + i_str);
	len_var = (int)ft_strlen(grpvar->global->array[i_var]->value);
	new_value = malloc(sizeof(char) * (len_endstr + len_var + 1));
	if (!new_value)
	{
		ft_puterror("Malloc failed");
		return (0);
	}
	ft_strlcpy(new_value, grpvar->global->array[i_var]->value, len_var + 1);
	ft_strlcat(new_value, root->value + i_str, len_endstr + len_var + 1);
	free(root->value);
	root->value = ft_strdup(new_value);
	free(new_value);
	return (1);
}

static int	update_root_null(t_dyntree *root, size_t i_str)
{
	char	*new_value;

	new_value = malloc(sizeof(char) * ft_strlen(root->value + i_str) + 1);
	if (!new_value)
	{
		ft_puterror("Malloc failed");
		return (0);
	}
	ft_strlcpy(new_value, root->value + i_str, ft_strlen(root->value));
	free(root->value);
	root->value = ft_strdup(new_value);
	free(new_value);
	return (1);
}
