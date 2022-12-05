/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellana <mtmrkaploun@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 00:27:02 by ellana            #+#    #+#             */
/*   Updated: 2021/11/14 12:56:48 by ellana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Function name : 
 * ft_lstmap
 *
 * Prototype : 
 * t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
 *
 * Fichiers de rendu :
 * 
 * Paramètres : 
 * #1. L’adresse du pointeur vers un élément.
 * #2. L’adresse de la fonction à appliquer.
 *
 * Valeur de retour : 
 * La nouvelle liste. NULL si l’allocation échoue.
 *
 * Fonctions externes autorisées : 
 * malloc, free
 *
 * Description : 
 * Itère sur la liste lst et applique la fonction f au
 * contenu de chaque élément. Crée une nouvelle liste
 * résultant des applications successives de f. la
 * fonction del est la pour detruire le contenu d un
 * element si necessaire
 */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	**out;
	t_list	*new;
	t_list	*first_el;

	first_el = ft_lstnew(f((*lst).content));
	out = &first_el;
	new = NULL;
	if (!first_el)
		return (NULL);
	while ((*lst).next)
	{
		lst = (*lst).next;
		new = ft_lstnew(f((*lst).content));
		if (!new)
		{
			ft_lstclear(out, del);
			return (NULL);
		}
		ft_lstadd_back(out, new);
	}
	return (*out);
}
