/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_var_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:16:42 by lray              #+#    #+#             */
/*   Updated: 2023/10/31 20:17:24 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*make_varname(char *varname, char *value, size_t i)
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
	return (varname);
}

char	*init_varname(char *varname)
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

char	*add_char(char *varname, char c)
{
	size_t	len;

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

char	*add_dollar(char *varname)
{
	size_t	len;

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
