/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mtmrkaploun@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 09:03:46 by mkaploun          #+#    #+#             */
/*   Updated: 2021/11/10 01:07:58 by ellana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	get_dim(char const *s, char c, int dim[2])
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	dim[0] = 0;
	dim[1] = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		len = 0;
		while (s[i] != c && s[i])
		{
			i++;
			len++;
		}
		dim[0]++;
		if (len > dim[1])
			dim[1] = len;
		while (s[i] == c)
			i++;
	}
}

static void	free_table(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static char	**alloc_space(int dim[2])
{
	int		i;
	char	**tab;

	i = 0;
	tab = malloc(sizeof(int *) * (dim[0] + 1));
	if (!tab)
		return (NULL);
	while (i < dim[0])
	{
		tab[i] = malloc(sizeof(int *) * (dim[1] + 1));
		if (!tab[i])
		{
			free_table(tab);
			return (NULL);
		}
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

static void	copy_str(char const *s, char c, char **tab)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		k = 0;
		while (s[i] != c && s[i])
		{
			tab[j][k] = s[i];
			k++;
			i++;
		}
		tab[j][k] = '\0';
		j++;
		while (s[i] == c)
			i++;
	}
}

char	**ft_split(char const *s, char c)
{
	int		dim[2];
	char	**tab;

	get_dim(s, c, dim);
	tab = alloc_space(dim);
	if (!tab)
		return (NULL);
	copy_str(s, c, tab);
	return (tab);
}
