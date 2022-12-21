#include "execution.h"

void	execution_print(t_execution *execution)
{
	int	i;

	i = 0;
	/* printf("Current executable : \n"); */
	/* executable_print(execution->current_executable); */
	printf("Executables : \n");
	executables_print(execution->executables);
	printf("Pipes : \n");
	print_pipes(execution->pipes, execution->executables_size);
	printf("Executable size : %d\n", (int )execution->executables_size);
	printf("Pids : ");
	int_lstprint(*execution->pids);
	printf("\n");
}
