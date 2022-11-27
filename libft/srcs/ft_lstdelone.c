/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellana <mtmrkaploun@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 00:27:02 by ellana            #+#    #+#             */
/*   Updated: 2021/11/12 18:16:19 by ellana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Function name : 
 * ft_lstdelone
 *
 * Prototype : 
 * void ft_lstdelone(t_list *lst, void (*del)(void *));
 *
 * Fichiers de rendu :
 * 
 * Paramètres : 
 * #1. L’élement à free
 * #2. L’adresse de la fonction permettant de
 * supprimer le contenu de l’élement.
 *
 * Valeur de retour : 
 * None
 *
 * Fonctions externes autorisées : 
 * free
 *
 * Description : 
 * Libère la mémoire de l’élément passé en argument
 * en utilisant la fonction del puis avec free(3). La
 * mémoire de next ne doit pas être free.
 */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del((*lst).content);
	free(lst);
}
