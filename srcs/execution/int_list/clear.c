/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:53:48 by mkaploun          #+#    #+#             */
/*   Updated: 2023/01/07 11:54:03 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "int_list.h"

void	int_lstclear(t_intlist **lst)
{
	t_intlist	*el;
	t_intlist	*next_el;

	next_el = NULL;
	el = *lst;
	while (el)
	{
		next_el = (*el).next;
		free(el);
		el = next_el;
	}
	*lst = NULL;
}
