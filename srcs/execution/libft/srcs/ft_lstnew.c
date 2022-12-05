/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellana <mtmrkaploun@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 00:27:02 by ellana            #+#    #+#             */
/*   Updated: 2021/11/11 23:35:42 by ellana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Function name : 
 * ft_lstnew
 *
 * Prototype : 
 * t_list *ft_lstnew(void *content);
 *
 * Fichiers de rendu :
 * 
 * Paramètres : 
 * #1. Le contenu du nouvel élément.
 *
 * Valeur de retour : 
 * Le nouvel element
 *
 * Fonctions externes autorisées : 
 * malloc 
 *
 * Description : 
 * Alloue (avec malloc(3)) et renvoie un nouvel
 * élément. la variable content est initialisée à
 * l’aide de la valeur du paramètre content. La
 * variable ’next’ est initialisée à NULL.
 */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*out;

	out = (t_list *)malloc(sizeof(t_list));
	if (!out)
		return (NULL);
	(*out).content = content;
	(*out).next = NULL;
	return (out);
}
