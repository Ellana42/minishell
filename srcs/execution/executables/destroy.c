#include "executables.h"

void	executables_dispose(t_executables *executables)
{
	ft_lstclear(executables, (void *)executable_destroy);
}

void	executables_free(t_executables *executables)
{
	free(executables);
}

void	executables_destroy(t_executables *executables)
{
	executables_dispose(executables);
	executables_free(executables);
}
