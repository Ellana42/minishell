/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_chain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:10:55 by mkaploun          #+#    #+#             */
/*   Updated: 2023/01/02 18:10:55 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lstutils.h"

void	_print_str(void *s)
{
	printf("%s,", (char *)s);
}

void	print_str_chain(t_list *lst)
{
	ft_lstiter(lst, &_print_str);
}
