/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_var.c                                      :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 19:49:33 by lray              #+#    #+#             */
/*   Updated: 2023/10/13 10:57:07 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int is_quote(char c);
static char *make_varname(char *varname, char *value, size_t i);
static char	*init_varname(char *varname);
static char *add_char(char *varname, char c);
static char *add_dollar(char *varname);
char *search_and_replace(char *value, char *varname, char *res, size_t *i);

int	replace_var(t_dyntree *root, t_grpvar *grpvar)
{
	size_t	i_child;
	size_t	i_str;
	char	quote;
	char	*varname;
	int		pos;

	varname = NULL;
	quote = 0;
	i_str = 0;
	if (root->type == TK_COMMAND || root->type == TK_ARGUMENT || root->type == TK_FILE)
	{
		while (root->value[i_str] != '\0')
		{
			if (is_quote(root->value[i_str]))
			{
				if (quote == 0)
					quote = root->value[i_str];
				else if (root->value[i_str] == quote)
					quote = 0;
			}
			if ((quote == 0 || quote == '"') && root->value[i_str] == '$')
			{
				varname = make_varname(varname, root->value, i_str);
				pos = grpvar_has(grpvar, GRPVAR_GLOBAL, varname);
				varname = add_dollar(varname);
				if (pos == -1)
					root->value = search_and_replace(root->value, varname, NULL, &i_str);
				else
					root->value = search_and_replace(root->value, varname, grpvar->global->array[pos]->value, &i_str);
				free(varname);
			}
			i_str++;
		}
	}
	i_child = 0;
	while (i_child < root->numChildren)
		if (!replace_var(root->children[i_child++], grpvar))
			return (0);
	return (1);
}

static int is_quote(char c)
{
	if (c == '\'' || c == '"')
		return (1);
	return (0);
}

static char *make_varname(char *varname, char *value, size_t i)
{
	i++;
	varname = init_varname(varname);
	if (!varname)
		return (NULL);
	while (value[i] != '\0' && (ft_isalnum(value[i]) || value[i] == '_'))
	{
		varname = add_char(varname, value[i]);
		i++;
	}
	return varname;
}

static char	*init_varname(char *varname)
{
	varname = malloc(sizeof(char));
	if (!varname)
	{
		ft_puterror("Malloc failed");
		return (NULL);
	}
	varname[0] = '\0';
	return (varname);
}

static char *add_char(char *varname, char c)
{
	size_t len;

	len = ft_strlen(varname) + 1;
	varname = ft_realloc(varname, sizeof(char) * len, sizeof(char) * (len + 1));
	varname[len] = '\0';
	if (!varname)
	{
		ft_puterror("Realloc failed");
		return (NULL);
	}

	varname = add_char_to_string(varname, c);
	return (varname);
}

static char *add_dollar(char *varname)
{
	size_t len;

	len = ft_strlen(varname) + 1;
	varname = ft_realloc(varname, sizeof(char) * len, sizeof(char) * (len + 1));
	if (!varname)
	{
		ft_puterror("Realloc failed");
		return (NULL);
	}
	ft_memmove(varname + 1, varname, len);
	varname[0] = '$';
	return (varname);
}

char	*search_and_replace(char *value, char *varname, char *res, size_t *i)
{
	size_t len_value;
	size_t len_varname;
	size_t len_res;
	size_t len_new;

	len_value = ft_strlen(value);
	len_varname = ft_strlen(varname);
	if (!res)
		len_res = 0;
	else
		len_res = ft_strlen(res);
	len_new = len_value - len_varname + len_res;
	value = ft_realloc(value, sizeof(char) * (len_value + 1), sizeof(char) * (len_new + 1));
	if (len_new > len_value)
	{
		ft_memmove(value + *i + (len_new - len_value), value + *i, len_new + 1);
		ft_memcpy(value + *i, res, len_res);
	}
	else
	{
		ft_memcpy(value + *i, res, len_res);
		ft_memmove(value + (*i) + len_res, value + (*i) + len_varname, len_value - len_varname + 1);
	}
	(*i) = len_res - 1;
	return (value);
}
