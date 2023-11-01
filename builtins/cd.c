/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 02:30:09 by mflury            #+#    #+#             */
/*   Updated: 2023/11/01 14:31:15 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*process_dash(t_ctx *ctx, char *input);
static char	*process_wave(t_ctx *ctx, char *input);
static int	jump(t_ctx *ctx, char *input);
static int	process_noarg(t_ctx *ctx);

int	builtin_cd(char **argv, t_ctx *ctx)
{
	if (argv && argv[1])
	{
		if (argv[1][0] == '-')
			argv[1] = process_dash(ctx, argv[1]);
		if (argv[1][0] == '~')
		{
			argv[1] = process_wave(ctx, argv[1]);
			if (argv[1] == NULL)
				return (2);
		}
		if (jump(ctx, argv[1]) == 0)
			return (3);
	}
	else
	{
		if (!process_noarg(ctx))
			return (1);
	}
	return (0);
}

static char	*process_dash(t_ctx *ctx, char *input)
{
	int		pos;
	char	*oldpwd;
	char	*new;

	if (ft_strlen(input) != 1)
	{
		ft_puterror("cd: bad usage: invalid option");
		return (NULL);
	}
	pos = grpvar_has(ctx->grpvar, GRPVAR_GLOBAL, "OLDPWD");
	if (pos == -1 || ctx->grpvar->global->array[pos]->value[0] == '\0')
	{
		ft_puterror("cd: OLDPWD not set");
		return (NULL);
	}
	oldpwd = ctx->grpvar->global->array[pos]->value;
	new = malloc(sizeof(char) * ft_strlen(oldpwd) + 1);
	ft_strlcpy(new, oldpwd, ft_strlen(oldpwd) + 1);
	printf("%s\n", oldpwd);
	free(input);
	return (new);
}

static char	*process_wave(t_ctx *ctx, char *input)
{
	int		pos;
	char	*home;
	char	*new;

	pos = grpvar_has(ctx->grpvar, GRPVAR_GLOBAL, "HOME");
	if (pos == -1 || ctx->grpvar->global->array[pos]->value[0] == '\0')
	{
		ft_puterror("cd: HOME not set");
		return (NULL);
	}
	home = ctx->grpvar->global->array[pos]->value;
	new = malloc(sizeof(char) * ft_strlen(home) + ft_strlen(input) + 1);
	if (!new)
	{
		ft_puterror("Malloc failed");
		return (NULL);
	}
	ft_strlcpy(new, home, ft_strlen(home) + 1);
	ft_strlcat(new, input + 1, ft_strlen(input) + ft_strlen(home) + 1);
	free(input);
	return (new);
}

static int	jump(t_ctx *ctx, char *input)
{
	char	*buf;

	buf = NULL;
	buf = getcwd(NULL, 0);
	grpvar_add(ctx->grpvar, GRPVAR_GLOBAL, "OLDPWD", buf);
	free(buf);
	if (chdir(input) == -1)
	{
		perror("minishell: cd");
		return (0);
	}
	buf = getcwd(NULL, 0);
	grpvar_add(ctx->grpvar, GRPVAR_GLOBAL, "PWD", buf);
	free(buf);
	return (1);
}

static int	process_noarg(t_ctx *ctx)
{
	int			pos;
	t_dynarrstr	*args;
	char		*home;

	args = NULL;
	pos = grpvar_has(ctx->grpvar, GRPVAR_GLOBAL, "HOME");
	if (pos == -1 || ctx->grpvar->global->array[pos]->value[0] == '\0')
	{
		ft_puterror("cd :HOME not set");
		return (0);
	}
	home = ctx->grpvar->global->array[pos]->value;
	args = dynarrstr_init(args);
	dynarrstr_add(args, "cd");
	dynarrstr_add(args, home);
	builtin_cd(args->array, ctx);
	dynarrstr_free(args);
	return (1);
}
