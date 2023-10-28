/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 20:30:19 by lray              #+#    #+#             */
/*   Updated: 2023/10/28 23:03:11 by lray             ###   ########.fr       */
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
		ctx->lstbltins = NULL;
		ctx->input = NULL;
		ctx->tklist = NULL;
		ctx->tree = NULL;
		ctx->grpvar = grpvar_init(envp);
		if (ctx->grpvar == NULL)
			return (NULL);
		ctx->lstbltins = lstbuiltins_init(ctx->lstbltins);
		if (!ctx->lstbltins)
			return (NULL);
		ctx->env = NULL;
		ctx->ret_code = 0;
		set_sigmode(&ctx->sigset, SIGMODE_NORMAL);
		return (ctx);
	}
	return (NULL);
}

void	ctx_show(t_ctx *ctx)
{
	grpvar_show(ctx->grpvar);
	printf("\n");
	lstbuiltins_show(ctx->lstbltins);
	printf("\n");
	printf("= Input SHOW =\n");
	printf("-> input : %s\n", ctx->input);
	printf("\n");
	dyntklist_show(ctx->tklist);
	printf("\n");
	printf("= DYNTREE SHOW =\n");
	dyntree_show(ctx->tree, 0);
	printf("\n");
	printf("Return code : %d\n", ctx->ret_code);
	printf("\n");
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
		if (ctx->lstbltins)
		{
			lstbuiltins_freeall(ctx->lstbltins);
			ctx->lstbltins = NULL;
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
		if (ctx->env)
		{
			env_free(ctx->env);
			ctx->env = NULL;
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
