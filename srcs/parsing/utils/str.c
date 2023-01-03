#include "utils.h"

void	str_clean(char *str, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		*str = '\0';
		i++;
	}
}

int	str_cpy(char *str, char *dst)
{
	if (!str)
		return (1);
	ft_strlcpy(dst, str, ft_strlen(str) + 1);
	return (0);
}

int	str_cat(char *str, char *dst)
{
	if (!str || !dst)
		return (0);
	dst += ft_strlen(dst);
	while (*str)
	{
		*dst = *str;
		str++;
		dst++;
	}
	dst = 0;
	return (0);
}

int	str_are_equal(char *str1, char *str2)
{
	if (!str1 || !str2)
		return (-1);
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (0);
		str1++;
		str2++;
	}
	if (*str1 != *str2)
		return (0);
	return (1);
}

int	str_store(char **dst, char *src, int start, int end)
{
	int	i;

	i = start;
	*dst = NULL;
	if (start > end)
		return (1);
	if (end > (int )ft_strlen(src))
		return (1);
	*dst = (char *)malloc(sizeof(char) * (end - start + 1));
	while (i < end)
	{
		(*dst)[i - start] = src[i];
		i++;
	}
	(*dst)[i - start] = '\0';
	return (0);
}
