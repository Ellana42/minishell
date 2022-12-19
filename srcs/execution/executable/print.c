#include "executable.h"

void	print_pipe(int *pipe)
{
	if (!pipe)
		printf("None\n");
	else
		printf("%d <- %d\n", pipe[0], pipe[1]);
}

void	executable_print(void *executable_ptr)
{
	int				i;
	t_executable	*executable;
	
	printf("-----------------\n");
	executable = (t_executable *)executable_ptr;
	i = 0;
	command_print(executable->command);
	printf("In pipe : ");
	print_pipe(executable->in_pipe);
	printf("Out pipe : ");
	print_pipe(executable->out_pipe);
	printf("Size infiles : %d\n", (int )executable->in_size);
	printf("Infiles : ");
	while (i < executable->in_size)
	{
		if (executable->in_files[i][1] == -1)
			printf("%d - ", executable->in_files[i][0]);
		else
			printf("(%d <- %d) - ", executable->in_files[i][0], executable->in_files[i][1]);
		i++;
	}
	printf("\n");
	printf("Size outfiles : %d\n", (int )executable->out_size);
	i = 0;
	printf("Outfiles : ");
	while (i < executable->out_size)
	{
		printf("%d - ", executable->out_files[i]);
		i++;
	}
	printf("\n");
	printf("-----------------\n");
}
