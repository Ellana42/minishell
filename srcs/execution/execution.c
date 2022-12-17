#include "execution.h"

int	execution(t_commands *commands, char **envp)
{
	t_execution		*execution;
	t_executable	*executable;
	int				i;

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
	waitpid(-1, NULL, 0);
	execution_close(execution);
	execution_destroy(execution);
	return (0);
}
