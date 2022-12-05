/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellana <mtmrkaploun@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:11:49 by ellana            #+#    #+#             */
/*   Updated: 2021/12/20 14:57:42 by ellana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	to_smth(char type, va_list *ap, char **str)
{
	if (type == 'd' || type == 'i')
		return (from_d_i(va_arg(*ap, int), str));
	else if (type == 'u')
		return (from_u(va_arg(*ap, unsigned int), str));
	else if (type == 'x' || type == 'X')
		return (from_hex(va_arg(*ap, unsigned int), type, str));
	else if (type == '%')
		return (from_c(type, str));
	else if (type == 'c')
		return (from_c((char )va_arg(*ap, int), str));
	else if (type == 's')
		return (from_s(va_arg(*ap, char *), str));
	else
		return (from_p(va_arg(*ap, void *), str));
}

int	transform(void	*format, va_list *ap, char **res)
{
	char	type;
	char	*input;
	size_t	len;
	int		status;

	input = (char *)format;
	len = ft_strlen(input);
	if (len == 0)
		return (0);
	else if (input[0] == '%')
	{
		type = input[len - 1];
		status = to_smth(type, ap, res);
		return (status);
	}
	if (format == NULL)
	{
		*res = NULL;
		return (0);
	}
	*res = ft_strdup(format);
	status = ft_strlen(format);
	if (!(*res))
		return (-1);
	return (status);
}

t_bilist	*ft_lstmap_trans(t_list *lst, va_list *ap)
{
	t_bilist	*new;
	t_bilist	*first_el;
	char		*res;
	int			len;

	res = NULL;
	len = transform((*lst).content, ap, &res);
	if (len == -1)
		return (NULL);
	first_el = ft_bilstnew(res, len);
	if (!first_el)
		return (NULL);
	while ((*lst).next)
	{
		lst = (*lst).next;
		len = transform((*lst).content, ap, &res);
		if (len == -1)
			return (ft_bilstclear(&first_el, &free));
		new = ft_bilstnew(res, len);
		if (!new)
			return (ft_bilstclear(&first_el, &free));
		ft_bilstadd_back(&first_el, new);
	}
	return (first_el);
}

int	ft_printf(const char *str, ...)
{
	va_list		ap;
	t_list		*in_lst;
	t_bilist	*out_lst;
	int			len;

	va_start(ap, str);
	in_lst = str_to_lst(str);
	if (!in_lst)
		return (-1);
	out_lst = ft_lstmap_trans(in_lst, &ap);
	if (!out_lst)
	{
		ft_lstclear(&in_lst, &free);
		return (-1);
	}
	len = lst_print(out_lst);
	va_end(ap);
	ft_lstclear(&in_lst, &free);
	ft_bilstclear(&out_lst, &free);
	return (len);
}
