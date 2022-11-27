/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellana <mtmrkaploun@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 00:27:02 by ellana            #+#    #+#             */
/*   Updated: 2021/11/10 15:05:18 by ellana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Function name : 
 * ft_putchar_fd
 *
 * Prototype : 
 * void ft_putchar_fd(char c, int fd);
 *
 * Fichiers de rendu :
 * 
 * Paramètres : 
 * #1. Le caractère à écrire.
 * #2. Le file descriptor sur lequel écrire.
 *
 * Fonctions externes autorisées : 
 * write 
 *
 * Valeur de retour : 
 * None
 *
 * Description : 
 * Écrit le caractère ’c’ sur le file descriptor
 * donné.
 */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
