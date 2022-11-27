/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellana <mtmrkaploun@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 00:27:02 by ellana            #+#    #+#             */
/*   Updated: 2021/11/10 14:24:17 by ellana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Function name : 
 * ft_striteri
 *
 * Prototype : 
 * void ft_striteri(char *s, void (*f)(unsigned int, char*));
 *
 * Fichiers de rendu :
 * 
 * Paramètres : 
 * #1. La chaine de caractères sur laquelle itérer.
 * #2. La fonction à appliquer à chaque caractère.
 *
 * Fonctions externes autorisées : 
 * None 
 *
 * Valeur de retour : 
 * None
 *
 * Description : 
 * Applique la fonction f à chaque caractère de la
 * chaîne de caractères transmise comme argument, et
 * en passant son index comme premier argument. Chaque
 * caractère est transmis par adresse à f pour être
 * modifié si nécessaire.
 */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;

	i = 0;
	while (s[i])
	{
		f(i, s + i);
		i++;
	}
}
