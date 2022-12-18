#include "execution.h"

int	execution(t_commands *commands, char **envp)
{
	t_execution		*execution;
	t_executable	*executable;
	int				i;
	int				pid;

	i = 0;
	execution = execution_alloc();
	execution_init(execution, commands, envp);
	printf("=============================\n");
	/* execution_print(execution); */
	
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
		/* printf("Waiting for %d\n", pid); */
		waitpid(pid, NULL, 0);
		i++;
	}
	execution_destroy(execution);
	return (0);
}
