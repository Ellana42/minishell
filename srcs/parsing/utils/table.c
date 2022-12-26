#include "utils.h"

void	table_print(char **table)
{
	int	i;

	i = 0;
	if (!table)
		return ;
	while (table[i])
	{
		printf("%d : %s\n", i, table[i]);
		i++;
	}
	printf("%d : %s\n", i, table[i]);
}

int	table_get_size(char **table)
{
	int	i;

	i = 0;
	if (!table)
		return (-1);
	while (table[i])
		i++;
	return (i);
}
