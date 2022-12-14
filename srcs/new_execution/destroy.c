#include "execution.h"

void	execution_dispose(t_execution *execution)
{
	free(execution->pipes);
	executables_destroy(execution->executables);
	free(execution->pids);
}

void	execution_free(t_execution *execution)
{
	free(execution);
}

void	execution_destroy(t_execution *execution)
{
	execution_dispose(execution);
	execution_free(execution);
}
