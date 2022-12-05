/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellana <mtmrkaploun@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 00:27:02 by ellana            #+#    #+#             */
/*   Updated: 2021/11/11 22:07:05 by ellana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Function name : 
 * ft_putendl_fd
 *
 * Prototype : 
 * void ft_putendl_fd(char *s, int fd);
 *
 * Fichiers de rendu :
 * 
 * Paramètres : 
 * #1. La chaine de caractères à écrire.
 * #2. Le file descriptor sur lequel écrire.
 *
 * Fonctions externes autorisées : 
 * write 
 *
 * Valeur de retour : 
 * None
 *
 * Description : 
 * Écrit La chaine de caractères ’s’ sur le file
 * descriptor donné, suivie d’un retour à la ligne.
 */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
	ft_putchar_fd('\n', fd);
}
