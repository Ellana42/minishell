#include "execution.h"

void	execution_move(t_execution *execution)
{
	t_executable	*executable;

	execution->executable_index++;
	executable = execution_get_executable_i(execution, execution->executable_index);
	execution->current_executable = executable;
}

void	execution_store_pid(t_execution *execution, int pid)
{
	execution->pids[execution->executable_index] = pid;
}