#include "utils.h"

void	mem_clean(char *ptr, int mem_size)
{
	int	i;

	i = 0;
	while (i < mem_size)
	{
		ptr[i] = '\0';
		i++;
	}
}
