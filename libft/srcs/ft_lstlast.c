/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellana <mtmrkaploun@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 00:27:02 by ellana            #+#    #+#             */
/*   Updated: 2021/11/12 17:03:14 by ellana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Function name : 
 * ft_lstlast
 *
 * Prototype : 
 * t_list *ft_lstlast(t_list *lst);
 *
 * Fichiers de rendu :
 * 
 * Paramètres : 
 * #1. Le début de la liste.
 *
 * Valeur de retour : 
 * Dernier élément de la liste
 *
 * Fonctions externes autorisées : 
 * None
 *
 * Description : 
 * Renvoie le dernier élément de la liste.
 */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while ((*lst).next)
		lst = (*lst).next;
	return (lst);
}
