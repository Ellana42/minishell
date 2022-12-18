#include "execution.h"

int	close_fd(int fd)
{
	if (fd == -1 || fd == 0 || fd == 1)
		return (0);
	if (close(fd) == -1)	
		return (1);
	return (0);
}

int	close_pipe(int *fd)
{
	if (!fd)
		return (0);
	if (close_fd(fd[0]))
		return (1);
	if (close_fd(fd[1]))
		return (1);
	return (0);
}
