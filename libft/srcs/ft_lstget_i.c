/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 21:44:30 by mkaploun          #+#    #+#             */
/*   Updated: 2022/12/26 21:44:31 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_lstget_i(t_list *lst, int index)
{
	int		i;

	i = 0;
	while (i < index)
	{
		if (!lst)
			return (NULL);
		lst = lst->next;
		i++;
	}
	if (!lst)
		return (NULL);
	return (lst->content);
}
