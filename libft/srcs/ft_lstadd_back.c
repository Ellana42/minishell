/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellana <mtmrkaploun@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 00:27:02 by ellana            #+#    #+#             */
/*   Updated: 2022/01/07 19:06:46 by ellana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Function name : 
 * ft_lstadd_back
 *
 * Prototype : 
 * void ft_lstadd_back(t_list **alst, t_list *new);
 *
 * Fichiers de rendu :
 * 
 * Paramètres : 
 * #1. L’adresse du pointeur vers le premier élément
 * de la liste.
 * #2. L’adresse du pointeur vers l’élément à rajouter
 * à la liste.
 *
 * Valeur de retour : 
 * None
 *
 * Fonctions externes autorisées : 
 * None
 *
 * Description : 
 * Ajoute l’élément new à la fin de la liste.
 */

#include "../includes/libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*last;

	if (!(*alst))
		*alst = new;
	else
	{
		last = ft_lstlast(*alst);
		(*last).next = new;
	}
}
