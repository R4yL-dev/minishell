/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 20:24:50 by lray              #+#    #+#             */
/*   Updated: 2023/11/01 12:13:47 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CTX_H
# define CTX_H

# include "../minishell.h"

# include <signal.h>

typedef struct s_ctx
{
	struct s_grpvar			*grpvar;
	struct s_lstbuiltins	*lstbltins;
	sigset_t				sigset;
	char					*input;
	struct s_dyntklist		*tklist;
	struct s_dyntree		*tree;
	struct s_env			*env;
	int						ret_code;
}	t_ctx;

t_ctx	*ctx_init(t_ctx *ctx, char **envp);
void	ctx_show(t_ctx *ctx);
void	ctx_free(t_ctx *ctx);
void	ctx_free_line(t_ctx *ctx);

int		var_set_init_value(t_ctx *ctx);

#endif
