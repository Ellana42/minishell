/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bilst_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellana <mtmrkaploun@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:04:48 by ellana            #+#    #+#             */
/*   Updated: 2021/12/16 18:22:08 by ellana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bilist	*ft_bilstnew(void *content, int size)
{
	t_bilist	*out;

	out = (t_bilist *)malloc(sizeof(t_bilist));
	if (!out)
		return (NULL);
	(*out).content = content;
	(*out).size = size;
	(*out).next = NULL;
	return (out);
}

void	*ft_bilstclear(t_bilist **lst, void (*del)(void *))
{
	t_bilist	*el;
	t_bilist	*next_el;

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
	return (NULL);
}

t_bilist	*ft_bilstlast(t_bilist *lst)
{
	while ((*lst).next)
		lst = (*lst).next;
	return (lst);
}

void	ft_bilstadd_back(t_bilist **alst, t_bilist *new)
{
	t_bilist	*last;

	last = ft_bilstlast(*alst);
	(*last).next = new;
}
