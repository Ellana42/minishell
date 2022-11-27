/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mtmrkaploun@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 09:03:46 by mkaploun          #+#    #+#             */
/*   Updated: 2021/11/08 18:31:19 by ellana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <errno.h>

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*out;

	len = ft_strlen(s1);
	out = (char *)malloc(sizeof(char) * (len + 1));
	if (!out)
	{
		errno = ENOMEM;
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		out[i] = s1[i];
		i++;
	}
	out[i] = '\0';
	return (out);
}
