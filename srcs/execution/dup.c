#include "execution.h"

int	execution_dup_in(int fd_in)
{
	if (dup2(fd_in, STDIN_FILENO) == -1)
	{
		printf("Issue with dup2 in\n");
		return (1);
	}
	return (0);
}

int	execution_dup_out(int fd_out)
{
	if (dup2(fd_out, STDOUT_FILENO) == -1)
	{
		printf("Issue with dup2 out\n");
		return (1);
	}
	return (0);
}
