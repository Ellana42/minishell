/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellana <mtmrkaploun@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:08:27 by ellana            #+#    #+#             */
/*   Updated: 2021/12/16 18:08:27 by ellana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*apply_s_flags(char *str, char *format)
{
	int	len_str;
	int	len_target;

	len_str = ft_strlen(str);
	len_target = has_size(format);
	if (has_size(format) == -1)
		return (str);
	else if (len_target < len_str)
		return (trim(str, len_target));
	else if (len_target > len_str && is_in_str('-', format))
		return (right_pad(str, len_target, ' '));
	else if (len_target > len_str)
		return (left_pad(str, len_target, ' '));
	else
		return (str);
}

char	*zero_pad(char *str, int len_target)
{
	char	sign;
	int		len_str;

	len_str = ft_strlen(str);
	if (len_target > len_str && is_in_str(str[0], "+- "))
	{
		sign = str[0];
		str[0] = '0';
		str = left_pad(str, len_target, '0');
		str[0] = sign;
		return (str);
	}
	else
		return (left_pad(str, len_target, '0'));
}

char	*apply_d_flags(char *str, char *format)
{
	int	len_target;

	len_target = has_size(format);
	if (is_in_str('+', format) && str[0] != '-')
		str = add_prefix(str, "+");
	else if (is_in_str(' ', format) && str[0] != '-')
		str = add_prefix(str, " ");
	if (len_target != -1 && is_in_str('-', format))
		str = right_pad(str, len_target, ' ');
	else if (len_target != -1 && is_in_str('0', format))
		str = zero_pad(str, len_target);
	else if (len_target != -1 && is_in_str('.', format))
		str = zero_pad(str, len_target);
	else if (len_target != -1)
		str = left_pad(str, len_target, ' ');
	return (str);
}

char	*apply_flags(char type, char *format, char *res)
{
	if (type == 'x' && is_in_str('#', format))
		return (add_prefix(res, "0x"));
	else if (type == 'X' && is_in_str('#', format))
		return (add_prefix(res, "0X"));
	else if (is_in_str(type, "diuxX"))
		return (apply_d_flags(res, format));
	else if (type == 's')
		return (apply_s_flags(res, format));
	return (res);
}
