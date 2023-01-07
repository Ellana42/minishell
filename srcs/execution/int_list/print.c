/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:53:48 by mkaploun          #+#    #+#             */
/*   Updated: 2023/01/07 11:54:04 by mkaploun         ###   ########.fr       */
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
