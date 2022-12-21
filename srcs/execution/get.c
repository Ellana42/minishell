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

t_command *execution_get_current_command(t_execution *execution)
{
	int				index;
	t_executable	*executable;

	index = execution->executable_index;
	executable = execution_get_current(execution);
	return (executable->command);
}

char *execution_get_current_command_name(t_execution *execution)
{
	return (command_get_name(execution_get_current_command(execution)));
}

char **execution_get_env(t_execution *execution)
{
	return (execution->envp);
}

int execution_get_pid(t_execution *execution)
{
	int	pid;

	if (!(*execution->pids))
		return (-1);
	return ((*execution->pids)->content);
}
