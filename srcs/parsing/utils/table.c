#include "utils.h"

void	table_print(char **table)
{
	int	i;

	i = 0;
	while (table[i])
	{
		printf("%d : %s\n", i, table[i]);
		i++;
	}
}
