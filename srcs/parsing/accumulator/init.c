#include "accumulator.h"

t_acc	*acc_alloc(void)
{
	t_acc	*acc;

	acc = (t_acc *)malloc(sizeof(t_acc));
	return (acc);
}

int	acc_init(t_acc *acc, size_t size)
{
	acc->is_empty = True;
	acc->size = size;
	acc->acc = (char *)malloc(sizeof(char) * (acc->size + 1));
	if (!acc->acc)
		return (1);
	acc_reset(acc);
	return (0);
}

void	acc_dispose(t_acc *acc)
{
	free(acc->acc);
}

void	acc_free(t_acc *acc)
{
	free(acc);
}

void	acc_destroy(t_acc *acc)
{
	acc_dispose(acc);
	acc_free(acc);
}
