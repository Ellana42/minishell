#include "execution.h"

t_executable *execution_get_executable_i(t_execution *execution, int index)
{
	return (executables_get_i(execution->executables, index));
}

t_executable *execution_get_current(t_execution *execution)
{
	int	index;

	index = execution->executable_index;
	return (executables_get_i(execution->executables, index));
}
