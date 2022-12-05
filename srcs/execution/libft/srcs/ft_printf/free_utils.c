/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellana <mtmrkaploun@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:09:04 by ellana            #+#    #+#             */
/*   Updated: 2021/12/16 18:09:04 by ellana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*free_buf(char *buf)
{
	free(buf);
	return (NULL);
}

void	*free_lst(t_list *lst)
{
	ft_lstclear(&lst, &free);
	return (NULL);
}

void	*free_lst_buf(t_list *lst, char *buf)
{
	free(buf);
	ft_lstclear(&lst, &free);
	return (NULL);
}

void	*ft_realloc(void *ptr, size_t size)
{
	void	*ptr2;

	ptr2 = malloc(size);
	free(ptr);
	return (ptr2);
}
