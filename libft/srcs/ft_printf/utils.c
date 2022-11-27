/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellana <mtmrkaploun@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:27:40 by ellana            #+#    #+#             */
/*   Updated: 2021/12/16 18:37:57 by ellana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	*str_to_lst(const char *str)
{
	t_list	*str_lst;
	t_list	*lst_el;
	int		j;
	char	*els;
	int		out;

	j = 0;
	out = copy_portion(str, &els, &j);
	str_lst = ft_lstnew(els);
	if (out == 1 || !str_lst)
		return (free_buf(els));
	while (out == 0)
	{
		out = copy_portion(str, &els, &j);
		if (out == 2)
		{
			free(els);
			return (str_lst);
		}
		lst_el = ft_lstnew(els);
		if (out == 1 || !lst_el)
			return (free_lst_buf(str_lst, els));
		ft_lstadd_back(&str_lst, lst_el);
	}
	return (str_lst);
}

int	has_size(char *format)
{
	int	i;

	i = 0;
	while (!ft_isdigit(format[i]) && format[i])
	{
		i++;
	}
	if (format[i])
		return (ft_atoi(format + i));
	else
		return (-1);
}

int	is_in_str(char c, char *str)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

int	is_type(char c)
{
	if (c == 'c' || c == 's' || c == 'p')
		return (1);
	else if (c == 'd' || c == 'i' || c == 'u')
		return (1);
	else if (c == 'x' || c == '%' || c == 'X')
		return (1);
	else
		return (0);
}

void	*ft_charset(void *b, char c, size_t len)
{
	size_t				i;
	unsigned char		*ptr;

	ptr = b;
	i = 0;
	while (i < len)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	ptr[i] = '\0';
	return (b);
}
