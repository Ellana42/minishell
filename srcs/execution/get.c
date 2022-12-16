#include "execution.h"

t_executable *execution_get_executable_i(t_execution *execution, int index)
{
	return (executables_get_i(execution->executables, index));
}
