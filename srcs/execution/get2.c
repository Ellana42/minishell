#include "execution.h"

int	execution_get_pid(t_execution *execution)
{
	int	pid;

	if (!(*execution->pids))
		return (-1);
	return ((*execution->pids)->content);
}

int	execution_is_command(t_execution *execution)
{
	if (command_get_name(execution_get_current_command(execution)))
		return (1);
	return (0);
}
