/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellana <mtmrkaploun@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 00:27:02 by ellana            #+#    #+#             */
/*   Updated: 2021/11/11 22:25:44 by ellana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Function name : 
 * ft_putnbr_fd
 *
 * Prototype : 
 * void ft_putnbr_fd(int n, int fd);
 *
 * Fichiers de rendu :
 * 
 * Paramètres : 
 * #1. L’integer à écrire.
 * #2. Le file descriptor sur lequel écrire.
 *
 * Fonctions externes autorisées : 
 * write 
 *
 * Valeur de retour : 
 * None
 *
 * Description : 
 * Écrit l’integer ’n’ sur le file descriptor donné.
 */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	ft_putstr_fd(ft_itoa(n), fd);
}
