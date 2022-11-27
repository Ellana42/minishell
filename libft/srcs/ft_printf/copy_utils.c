/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellana <mtmrkaploun@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:09:12 by ellana            #+#    #+#             */
/*   Updated: 2021/12/16 18:09:12 by ellana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*copy_format(const char *str, int *j, char *el)
{
	int	i;

	i = 1;
	el[i - 1] = '%';
	(*j)++;
	while (!is_type(str[*j]))
	{
		el[i] = str[*j];
		(*j)++;
		i++;
	}
	el[i] = str[*j];
	(*j)++;
	el[i + 1] = '\0';
	return (el);
}

char	*copy_str(const char *str, int *j, char *el)
{
	int	i;

	i = 0;
	while (str[*j] && str[*j] != '%')
	{
		el[i] = str[*j];
		i++;
		(*j)++;
	}
	el[i] = '\0';
	return (el);
}

int	copy_portion(const char *str, char **els, int *j)
{
	size_t	len;

	len = ft_strlen(str);
	*els = (char *)malloc(sizeof(char) * (len + 1));
	if (!(*els))
		return (1);
	if (str[*j] == '%')
		copy_format(str, j, *els);
	else if (str[*j] != '\0')
		copy_str(str, j, *els);
	else
	{
		(*els)[0] = '\0';
		return (2);
	}
	return (0);
}
