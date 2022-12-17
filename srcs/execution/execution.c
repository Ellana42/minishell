#include "execution.h"

// TODO fix fd closing for first and last command
int	execution(t_commands *commands, char **envp)
{
	t_execution	*execution;
	int	fd[2];
	t_executable	*executable;

	execution = execution_alloc();
	execution_init(execution, commands, envp);
	execution_print(execution);
	
	executable = execution_get_current(execution);
	execution_move(execution);
	execution_launch_exec(execution);
	/* executable_get_fds_close(executable, fd); */
	/* execution_close_unused(execution, execution->executable_index); */
	/* close(fd[0]); */
	/* close(fd[1]); */
	execution_close(execution);
	execution_destroy(execution);
	return (0);
}
