/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:41:13 by lray              #+#    #+#             */
/*   Updated: 2023/10/29 00:26:08 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPES_LIST_H
# define PIPES_LIST_H

int		**pipes_list_create(int num_pipes);
void	pipes_list_show(int **pipes_list, int num_pipes);
void	pipes_list_free(int **pipes_list, int num_pipes);

#endif
