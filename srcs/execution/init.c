#include "execution.h"

t_execution	*execution_alloc(void)
{
	t_execution	*execution;

	execution = (t_execution *)malloc(sizeof(t_execution));
	return (execution);
}

int	execution_init(t_execution *execution, t_commands *commands, int index)
{
	size_t	commands_size;
	int		i;
	t_executable	*executable;

	i = 0;
	commands_size = commands_get_size(commands);
	execution->executables_size = commands_size;
	execution->executable_index = 0;
	execution->current_executable = NULL;
	execution->executables = NULL;
	execution->pids = NULL;
	init_pipes(&execution->pipes, commands_size);
	if (execution->executables_size == 0)
		return (0);
	execution->executables = executables_alloc(); 
	if (!execution->executables)
		return (1);
	if (executables_init(execution->executables, commands, execution->pipes))
		return (1);
	executable = executables_get_i(execution->executables, 0);
	execution->current_executable = executable;
	execution->pids = (int *)malloc(sizeof(int) * (commands_size + 1));
	if (!execution->pids)
		return (1); // TODO deal with this shit
	while (i < execution->executables_size)
	{
		execution->pids[i] = -2;
		i++;
	}
	return (0);
}
