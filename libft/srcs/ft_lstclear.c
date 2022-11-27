/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellana <mtmrkaploun@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 00:27:02 by ellana            #+#    #+#             */
/*   Updated: 2021/11/16 16:01:42 by ellana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Function name : 
 * ft_lstclear
 *
 * Prototype : 
 * void ft_lstclear(t_list **lst, void (*del)(void *));
 *
 * Fichiers de rendu :
 * 
 * Paramètres : 
 * #1. L’adresse du pointeur vers un élément.
 * #2. L’adresse de la fonction permettant de
 * supprimer le contenu d’un élément.
 *
 * Valeur de retour : 
 * None
 *
 * Fonctions externes autorisées : 
 * free
 *
 * Description : 
 * Supprime et libère la mémoire de l’élément passé en
 * paramètre, et de tous les élements qui suivent, à
 * l’aide de del et de free(3)
 * Enfin, le pointeur initial doit être mis à NULL.
 */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*el;
	t_list	*next_el;

	next_el = NULL;
	el = *lst;
	while (el)
	{
		next_el = (*el).next;
		del((*el).content);
		free(el);
		el = next_el;
	}
	*lst = NULL;
}
