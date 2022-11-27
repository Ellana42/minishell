/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_conv_xp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellana <mtmrkaploun@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:10:30 by ellana            #+#    #+#             */
/*   Updated: 2021/12/16 18:10:48 by ellana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	hex(unsigned int n, char type)
{
	char	str[16];

	if (type == 'X')
		ft_strlcpy(str, "0123456789ABCDEF", 17);
	else
		ft_strlcpy(str, "0123456789abcdef", 17);
	return (str[n]);
}

char	*reverse_str(char *str)
{
	size_t	i;
	size_t	len;
	char	c;

	len = ft_strlen(str);
	i = 0;
	while (i < len / 2)
	{
		c = str[len - i - 1];
		str[len - i - 1] = str[i];
		str[i] = c;
		i++;
	}
	return (str);
}

int	from_hex(long int n, char type, char **str)
{
	int					i;
	int					rem;
	unsigned long long	nb;

	nb = (unsigned long long )n;
	*str = malloc(sizeof(char) * 17);
	if (!(*str))
		return (-1);
	i = 0;
	while (nb != 0)
	{
		rem = nb % 16;
		nb = nb / 16;
		(*str)[i] = hex(rem, type);
		i++;
	}
	(*str)[i] = '\0';
	if ((*str)[0] == '\0')
	{
		(*str)[0] = '0';
		(*str)[1] = '\0';
	}
	*str = reverse_str(*str);
	return (ft_strlen(*str));
}

char	*add_prefix(char *str, char *prefix)
{
	size_t	len;
	int		i;
	int		j;
	char	*out;

	i = -1;
	j = 0;
	len = ft_strlen(str) + ft_strlen(prefix) + 1;
	out = (char *)malloc(sizeof(char) * len);
	if (!out)
		return (NULL);
	while (prefix[++i])
		out[i] = prefix[i];
	while (str[j])
	{
		out[i] = str[j];
		i++;
		j++;
	}
	out[i] = '\0';
	free(str);
	return (out);
}

int	from_p(void *ptr, char **str)
{
	intptr_t	p;

	p = (intptr_t)ptr;
	if (from_hex(p, 'x', str) == -1)
		return (-1);
	*str = add_prefix(*str, "0x");
	if (!(*str))
		return (-1);
	return (ft_strlen(*str));
}
