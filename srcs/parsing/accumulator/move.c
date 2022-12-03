#include "accumulator.h"

int	acc_move(t_acc *acc)
{
	(acc->ptr)++;
	(acc->i)++;
	return (0);
}

void	acc_reset(t_acc *acc)
{
	int	i;

	i = 0;
	while (i <= acc->size)
	{
		(acc->acc)[i] = '\0';
		i++;
	}
	acc->i = 0;
	acc->ptr = acc->acc;
}

int	acc_is_empty(t_acc *acc)
{
	return (acc->i == 0);
}

int	acc_accumulate(t_acc *acc, char c)
{
	*(acc->ptr) = c;
	acc_move(acc);
	return (0);
}

int	acc_concat(t_acc *acc, char *str)
{
	size_t	new_size;
	size_t	len_str;
	char	*tmp;

	len_str = ft_strlen(str);
	new_size = acc->size + len_str;

	tmp = (char *)malloc(sizeof(char) * (new_size + 1));
	if (!tmp)
		return (1);
	mem_clean(tmp, new_size + 1);
	str_cpy(acc->acc, tmp);
	str_cat(str, tmp);
	free(acc->acc);
	acc->acc = tmp;
	acc->size = new_size;
	acc->i += len_str;
	acc->ptr = &(acc->acc[acc->i]);
	return (0);
}
