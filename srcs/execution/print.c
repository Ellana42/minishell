#include "execution.h"

void	execution_print(t_execution *execution)
{
	int	i;

	i = 0;
	// TODO unccomment when current exe init
	/* printf("Current executable : \n"); */
	/* executable_print(execution->current_executable); */
	printf("Executables : \n");
	executables_print(execution->executables);
	printf("Pipes : \n");
	print_pipes(execution->pipes, execution->executables_size);
	printf("Executable size : %d\n", (int )execution->executables_size);
	while (i < execution->executables_size)
	{
		printf("%d - ", execution->pids[i]);
		i++;
	}
	printf("\n");
}
