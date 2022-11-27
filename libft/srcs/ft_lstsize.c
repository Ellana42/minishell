/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellana <mtmrkaploun@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 00:27:02 by ellana            #+#    #+#             */
/*   Updated: 2022/01/08 12:09:06 by ellana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Function name : 
 * ft_lstsize
 *
 * Prototype : 
 * int ft_lstsize(t_list *lst);
 *
 * Fichiers de rendu :
 * 
 * Paramètres : 
 * #1. Le début de la liste.
 *
 * Valeur de retour : 
 * Taille de la liste.
 *
 * Fonctions externes autorisées : 
 * None
 *
 * Description : 
 * Compte le nombre d’éléments de la liste.
 */

#include "../includes/libft.h"

int	ft_lstsize(t_list *lst)
{
	int	len;

	if (!lst)
		return (0);
	len = 0;
	while (lst)
	{
		lst = (*lst).next;
		len++;
	}
	return (len);
}
