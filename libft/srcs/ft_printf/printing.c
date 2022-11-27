/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellana <mtmrkaploun@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:27:26 by ellana            #+#    #+#             */
/*   Updated: 2021/12/20 15:08:25 by ellana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	lst_print(t_bilist *lst)
{
	int		len;
	int		size;
	char	*content;

	len = 0;
	while (lst)
	{
		size = (*lst).size;
		content = (*lst).content;
		if (size == 1)
		{
			if (content[0] == 0)
				write(1, content, 1);
		}
		ft_putstr_fd(content, 1);
		len += size;
		lst = (*lst).next;
	}
	return (len);
}
