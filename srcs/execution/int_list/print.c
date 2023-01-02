/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellana <mtmrkaploun@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:09:15 by ellana            #+#    #+#             */
/*   Updated: 2023/01/02 18:09:31 by ellana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "int_list.h"

void	int_lstiter(t_intlist *lst, void (*f)(int))
{
	while (lst)
	{
		f((*lst).content);
		lst = (*lst).next;
	}
}

void	_int_print(int i)
{
	printf("%d, ", i);
}

void	int_lstprint(t_intlist *lst)
{
	if (lst)
		int_lstiter(lst, &_int_print);
	printf("\n");
}
