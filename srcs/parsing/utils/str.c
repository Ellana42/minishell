#include "utils.h"

void	str_clean(char *str, size_t len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		*str = '\0';
		i++;
	}
}

int str_cpy(char *str, char *dst)
{
	if (!str || !dst)
		return (0);
	while (*str)
	{
		*dst = *str;
		str++;
		dst++;
	}
	dst = 0;
	return (0);
}

int str_cat(char *str, char *dst)
{
	if (!str || !dst)
		return (0);
	str += ft_strlen(dst);
	while (*str)
	{
		*dst = *str;
		str++;
		dst++;
	}
	dst = 0;
	return (0);
}
