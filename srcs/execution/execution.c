#include "execution.h"

int	execution(t_commands *commands, char **envp)
{
	t_execution		*execution;
	t_executable	*executable;
	int				i;
	int				pid;
	int				exit_status;

	i = 0;
	execution = execution_alloc();
	if (execution_init(execution, commands, envp))
		return (1);
	
	while (i < execution->executables_size)
	{
		execution_fork_process(execution);
		execution_move(execution);
		i++;
	}

	execution_close(execution);
	i = 0;
	while (i < execution->executables_size)
	{
		pid = execution_get_pid(execution, i);
		waitpid(pid, &exit_status, 0);
		i++;
	}
	execution_destroy(execution);
	return (exit_status);
}
