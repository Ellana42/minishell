#include "execution.h"

int	execution(t_commands *commands, char **envp)
{
	t_execution	*execution;

	execution = execution_alloc();
	execution_init(execution, commands, 0);
	execution_print(execution);
	execution_destroy(execution);
	return (0);
}
