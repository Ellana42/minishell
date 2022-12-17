#include "execution.h"

int	close_fd(int fd)
{
	if (fd == -1)
		return (0);
	if (close(fd) == -1)	
	{
		printf("Failed to close fd %d\n", fd);
		return (1);
	}
	return (0);
}

int	close_pipe(int *fd)
{
	if (!fd)
		return (0);
	if (close_fd(fd[0]))
	{
		printf("Fail close first element of pipe\n");
		return (1);
	}
	if (close_fd(fd[1]))
	{
		printf("Fail close second element of pipe\n");
		return (1);
	}
	return (0);
}
