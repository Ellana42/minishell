/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:53:51 by mkaploun          #+#    #+#             */
/*   Updated: 2023/01/07 11:56:07 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lstutils.h"

void	*lst_get_i(t_list *lst, int i)
{
	int	j;

	j = 0;
	if (i < 0 || i > ft_lstsize(lst))
		return (NULL);
	while (j < i)
	{
		lst = lst->next;
		if (!lst)
			return (NULL);
		j++;
	}
	return ((char *)lst->content);
}

t_list	*lst_get_i_lst(t_list *lst, int i)
{
	int	j;

	j = 0;
	if (i < 0 || i > ft_lstsize(lst))
		return (NULL);
	while (j < i)
	{
		lst = lst->next;
		if (!lst)
			return (NULL);
		j++;
	}
	return (lst);
}

char	*lst_get_last(t_list *lst)
{
	int		size;
	int		j;

	size = ft_lstsize(lst);
	j = 0;
	if (!lst)
		return (NULL);
	while (j < size - 1)
	{
		lst = lst->next;
		j++;
	}
	return ((char *)(lst->content));
}
