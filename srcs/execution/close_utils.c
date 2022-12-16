#include "execution.h"

int	close_fd(int fd)
{
	if (fd != -1)
		return (close(fd));
	return (0);
}

int	close_pipe(int fd1, int fd2)
{
	if (close_fd(fd1))
		return (1);
	return (close_fd(fd2));
}
