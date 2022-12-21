#include "execution.h"

int	execution(t_commands *commands, char **envp)
{
	t_execution		*execution;
	t_executable	*executable;
	int				i;
	int				pid;
	int				exit_status;

	exit_status = 0;
	i = 0;
	execution = execution_alloc();
	if (execution_init(execution, commands, envp))
	{
		execution_close(execution);
		execution_destroy(execution);
		return (1);
	}
	/* execution_print(execution); */
	
	while (i < execution->executables_size)
	{
		if (execution_fork_process(execution))
		{
			execution_close(execution);
			execution_destroy(execution);
			return (1);
		}
		execution_move(execution);
		i++;
	}
	execution_close(execution); // TODO deal with close error ?
	i = 0;
	while (i < execution->executables_size)
	{
		pid = execution_get_pid(execution);
		waitpid(pid, &exit_status, 0);
		if (execution_pop_pid(execution, &pid))
			return (1);
		i++;
	}
	execution_destroy(execution);
	return (exit_status);
}
