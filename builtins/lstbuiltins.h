/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstbuiltins.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:28:13 by lray              #+#    #+#             */
/*   Updated: 2023/10/31 20:39:46 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LSTBUILTINS_H
# define LSTBUILTINS_H

typedef struct s_lstbuiltins
{
	char					*name;
	int						(*func)(char **argv, t_ctx *ctx);
	struct s_lstbuiltins	*next;

}	t_lstbuiltins;

t_lstbuiltins	*lstbuiltins_new(char *n, int (*func)(char **argv, t_ctx *ctx));
t_lstbuiltins	*lstbuiltins_init(t_lstbuiltins *head);
t_lstbuiltins	*lstbuiltins_getlast(t_lstbuiltins *head);
int				lstbuiltins_add(t_lstbuiltins *head, t_lstbuiltins *new);
void			lstbuiltins_show(t_lstbuiltins *head);
void			lstbuiltins_free(t_lstbuiltins *node);
void			lstbuiltins_freeall(t_lstbuiltins *head);

t_lstbuiltins	*lstbuiltins_has(t_lstbuiltins *head, char *name);
int				lstbuiltins_exec(t_lstbuiltins *h, char *n, char **a, t_ctx *c);

#endif
