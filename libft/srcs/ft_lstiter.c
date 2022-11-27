/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellana <mtmrkaploun@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 00:27:02 by ellana            #+#    #+#             */
/*   Updated: 2021/11/12 18:47:47 by ellana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Function name : 
 * ft_lstiter
 *
 * Prototype : 
 * void ft_lstiter(t_list *lst, void (*f)(void *));
 *
 * Fichiers de rendu :
 * 
 * Paramètres : 
 * #1 L’adresse du pointeur vers un élément.
 * #2. L’adresse de la fonction à appliquer.
 *
 * Valeur de retour : 
 * None
 *
 * Fonctions externes autorisées : 
 * None
 *
 * Description : 
 * Itère sur la list lst et applique la fonction f au
 * contenu chaque élément.
 */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f((*lst).content);
		lst = (*lst).next;
	}
}
