/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellana <mtmrkaploun@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:09:31 by ellana            #+#    #+#             */
/*   Updated: 2021/12/16 18:09:33 by ellana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*trim(char *str, int len)
{
	if (len < (int)ft_strlen(str))
		str[len + 1] = '\0';
	return (str);
}

char	*left_pad(char *str, int len, char c)
{
	int		len_str;
	int		len_prefix;
	char	*prefix;

	len_str = (int )ft_strlen(str);
	if (len > len_str)
	{
		len_prefix = len - len_str;
		prefix = malloc(sizeof(char) * (len_prefix + 1));
		ft_charset(prefix, c, len_prefix);
		str = add_prefix(str, prefix);
		free(prefix);
	}
	return (str);
}

char	*right_pad(char *str, int len, char c)
{
	int		len_str;
	char	*prefix;
	char	*str_cp;
	int		len_prefix;

	len_str = (int )ft_strlen(str);
	if (len > len_str)
	{
		str_cp = str;
		len_prefix = len - len_str;
		prefix = malloc(sizeof(char) * (len_prefix + 1));
		ft_charset(prefix, c, len_prefix);
		str = add_prefix(prefix, str);
		free(str_cp);
	}
	return (str);
}
