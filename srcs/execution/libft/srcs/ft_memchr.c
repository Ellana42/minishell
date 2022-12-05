/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mtmrkaploun@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 09:03:46 by mkaploun          #+#    #+#             */
/*   Updated: 2021/11/05 16:25:22 by ellana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	x;
	size_t			i;

	x = c;
	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == x)
			return ((void *)s + i);
		i++;
	}
	if (((unsigned char *)s)[i] == x)
		return ((void *)s + i);
	else
		return (NULL);
}
