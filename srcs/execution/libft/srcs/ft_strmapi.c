/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellana <mtmrkaploun@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 00:27:02 by ellana            #+#    #+#             */
/*   Updated: 2021/11/10 12:39:27 by ellana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Function name : 
 * ft_strmapi
 *
 * Prototype : 
 * char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
 *
 * Fichiers de rendu :
 * 
 * Paramètres : 
 * #1. La chaine de caractères sur laquelle itérer
 * #2. La fonction à appliquer à chaque caractère.
 *
 * Fonctions externes autorisées : 
 * malloc 
 *
 * Valeur de retour : 
 * La chaine de caractères résultant des applications
 * successives de f. Retourne NULL si l’allocation
 * échoue.
 *
 * Description : 
 * Applique la fonction ’f’ à chaque caractère de la
 * chaine de caractères passée en argument pour créer
 * une nouvelle chaine de caractères (avec malloc(3))
 * résultant des applications successives de ’f’.
 */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	int		i;
	char	*out;

	len = ft_strlen(s);
	out = malloc(sizeof(char) * (len + 1));
	if (!out)
		return (NULL);
	i = 0;
	while (s[i])
	{
		out[i] = f(i, s[i]);
		i++;
	}
	out[i] = '\0';
	return (out);
}
