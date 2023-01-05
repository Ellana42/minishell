#include "execution.h"

void	execution_print(t_execution *execution)
{
	printf("Executables : \n");
	executables_print(execution->executables);
	printf("Pipes : \n");
	print_pipes(execution->pipes);
	printf("Executable size : %d\n", (int )execution->executables_size);
	printf("Pids : ");
	int_lstprint(*execution->pids);
	printf("\n");
}

void	execution_print_full(t_execution *execution)
{
	execution_print(execution);
	minishell_print(execution_get_minishell(execution), 1);
}
