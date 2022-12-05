/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mtmrkaploun@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 09:03:46 by mkaploun          #+#    #+#             */
/*   Updated: 2021/11/08 22:52:12 by ellana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <errno.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*out;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	out = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!out)
		return (NULL);
	ft_strlcpy(out, s1, len_s1 + 1);
	ft_strlcat(out, s2, len_s1 + len_s2 + 1);
	return (out);
}
