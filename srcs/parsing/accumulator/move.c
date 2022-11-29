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
	while (i < acc->size)
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
	char	*tmp;
	size_t len_acc;

	if (!str)
		return (0);
	len_acc = ft_strlen(acc->acc);
	acc->size += ft_strlen(str);
	tmp = (char *)malloc(sizeof(char) * (acc->size + 1)); // TODO check malloc
	ft_strlcpy(tmp, acc->acc, len_acc + 1);	
	free(acc->acc);
	ft_strlcat(tmp, str, acc->size + 1);
	acc->acc = tmp;
	acc->i += ft_strlen(str);
	acc->ptr = &(acc->acc[acc->i]);
	return (0);
}
