/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mtmrkaploun@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 09:03:46 by mkaploun          #+#    #+#             */
/*   Updated: 2022/03/31 14:02:59 by ellana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_pow_(int a, int b)
{
	if (b <= 0)
		return (1);
	if (b == 1)
		return (a);
	return (a * ft_pow_(a, b - 1));
}

static int	highest_pow(int n)
{
	int	i;

	i = 9;
	while (n / ft_pow_(10, i) == 0 && i > 0)
		i--;
	return (i);
}

static void	ft_abs(int n, unsigned int *nb, int *neg)
{
	*neg = 0;
	if (n >= 0)
		*nb = n;
	else
	{
		*nb = -n;
		*neg = 1;
	}
}

char	*ft_itoa(int n)
{
	unsigned int	nb;
	int				neg;
	char			*str;
	int				i;
	int				hp;

	nb = 0;
	neg = 0;
	i = 0;
	ft_abs(n, &nb, &neg);
	hp = highest_pow(nb);
	str = malloc(sizeof(char) * (neg + hp + 2));
	if (!str)
		return (NULL);
	if (neg)
		str[0] = '-';
	while (i < hp + 1)
	{
		str[neg + i] = (nb / ft_pow_(10, hp - i)) + 48;
		nb %= ft_pow_(10, hp - i);
		i++;
	}
	str[neg + i] = '\0';
	return (str);
}
