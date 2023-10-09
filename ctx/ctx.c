/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 20:30:19 by lray              #+#    #+#             */
/*   Updated: 2023/10/09 13:25:00 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_ctx	*ctx_init(t_ctx *ctx, char **envp)
{
	printf("\e[1;1H\e[2J");
	if (ctx == NULL)
	{
		ctx = malloc(sizeof(t_ctx));
		if (ctx == NULL)
		{
			ft_puterror("Malloc failed");
			return (NULL);
		}
		ctx->grpvar = NULL;
		ctx->input = NULL;
		ctx->tklist = NULL;
		ctx->tree = NULL;
		ctx->grpvar = grpvar_init(envp);
		if (ctx->grpvar == NULL)
			return (NULL);
		return (ctx);
	}
	return (NULL);
}

void	ctx_free(t_ctx *ctx)
{
	if (ctx != NULL)
	{
		if (ctx->grpvar)
		{
			grpvar_free(ctx->grpvar);
			ctx->grpvar = NULL;
		}
		if (ctx->input)
		{
			free(ctx->input);
			ctx->input = NULL;
		}
		if (ctx->tklist)
		{
			dyntklist_free(ctx->tklist);
			ctx->tklist = NULL;
		}
		if (ctx->tree)
		{
			dyntree_free(ctx->tree);
			ctx->tree = NULL;
		}
		free(ctx);
		ctx = NULL;
	}
}

void	ctx_free_line(t_ctx *ctx)
{
	if (ctx->input)
	{
		free(ctx->input);
		ctx->input = NULL;
	}
	if (ctx->tklist)
	{
		dyntklist_free(ctx->tklist);
		ctx->tklist = NULL;
	}
	if (ctx->tree)
	{
		dyntree_free(ctx->tree);
		ctx->tree = NULL;
	}
}
