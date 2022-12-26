#include "execution.h"

int	execution_get_pid(t_execution *execution)
{
	int	pid;

	if (!(*execution->pids))
		return (-1);
	return ((*execution->pids)->content);
}
