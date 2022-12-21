#include "execution.h"

extern t_glob *glob;

t_execution	*execution_alloc(void)
{
	t_execution	*execution;

	execution = (t_execution *)malloc(sizeof(t_execution));
	if (!execution)
		return (execution);
	execution->pipes = NULL;
	execution->executables = NULL;
	execution->pids = NULL;
	execution->current_executable = NULL;
	return (execution);
}

int	execution_init(t_execution *execution, t_commands *commands, char **envp)
{
	size_t	commands_size;
	int		i;
	t_executable	*executable;

	if (!execution)
		return (1);
	i = 0;
	commands_size = commands_get_size(commands);
	execution->executables_size = commands_size;
	execution->executable_index = 0;
	execution->envp = envp;
	if (init_pipes(&execution->pipes, commands_size))
		return (1);
	execution->executables = executables_alloc(); 
	if (executables_init(execution->executables, commands, execution->pipes))
		return (1);
	executable = executables_get_i(execution->executables, 0);
	execution->current_executable = executable;
	execution->pids = intlstinit();
	if (!execution->pids)
		return (1); // TODO deal with this shit
	/* glob->pids = execution->pids; */
	return (0);
}
