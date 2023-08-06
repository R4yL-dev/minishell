/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 00:05:35 by lray              #+#    #+#             */
/*   Updated: 2023/02/20 23:13:30 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Desc :
		Érit la chaie de caractères s sur le descripteur de fichier donné
		suivie d'un retour à la ligne.

	Params :
		- s : La chaine de caracères à écrire.
		- fd Le descripteur de fichier sur lequel écrire.

	Ret :
		- Aucun
*/

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}
