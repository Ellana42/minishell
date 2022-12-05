/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellana <mtmrkaploun@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 00:27:02 by ellana            #+#    #+#             */
/*   Updated: 2022/01/08 13:07:11 by ellana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Function name : 
 * ft_putstr_fd
 *
 * Prototype : 
 * void ft_putstr_fd(char *s, int fd);
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
 * Écrit la chaine de caractères ’s’ sur le file
 * descriptor donné.
 */

#include "../includes/libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

void	ft_putstr(char *s)
{
	ft_putstr_fd(s, 1);
}
