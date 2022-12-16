#include "execution.h"

// TODO add executable index and init current executable
int	execution(t_commands *commands, char **envp)
{
	t_execution	*execution;
	int	fd[2];
	t_executable	*executable;

	execution = execution_alloc();
	execution_init(execution, commands, 0);
	execution_print(execution);
	
	executable = executables_get_i(execution->executables, 1);
	executable_get_fds_close(executable, fd);
	execution_close_unused(execution, 1);
	close(fd[0]);
	close(fd[1]);
	/* execution_close(execution); */
	execution_destroy(execution);
	return (0);
}
