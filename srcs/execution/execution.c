#include "execution.h"

// TODO fix fd closing for first and last command
int	execution(t_commands *commands, char **envp)
{
	t_execution	*execution;
	t_executable	*executable;

	execution = execution_alloc();
	execution_init(execution, commands, envp);
	/* execution_print(execution); */
	
	executable = execution_get_current(execution);
	execution_fork_process(execution);
	waitpid(-1, NULL, 0);
	execution_close(execution);
	execution_destroy(execution);
	return (0);
}
