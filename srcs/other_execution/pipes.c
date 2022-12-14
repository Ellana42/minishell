#include "execution.h"

int	init_pipes(int ***pipes, int commands_size)
{
	int	i;
	int	pipefd[2];

	(*pipes) = (int **)malloc(sizeof(int *) * (commands_size));
	if (!pipes)
		return (1);
	i = 0;
	while (i < commands_size - 1)
	{
		(*pipes)[i] = (int *)malloc(sizeof(int) * 2);
		if (!(*pipes)[i])
			return (1);
		pipe(pipefd);
		(*pipes)[i][0] = pipefd[0];
		(*pipes)[i][1] = pipefd[1];
		i++;
	}
	pipes[i] = NULL;
	return (0);
}

void	print_pipes(int **pipes, int commands_size)
{
	int	i;

	i = 0;
	printf("_____________\n");
	while (pipes[i])
	{
		printf("|     |     |\n");
		printf("|  %d  |  %d  |\n", pipes[i][0], pipes[i][1]);
		i++;
	}
	printf("_____________\n");
}

int	get_fd_in(int **pipes, int index_cmd)
{
	if (index_cmd == 0)
		return (STDIN_FILENO);
	return (pipes[index_cmd - 1][0]);
}

int	get_fd_out(int **pipes, int index_cmd, int commands_size)
{
	if (index_cmd == commands_size - 1)
		return (STDOUT_FILENO);
	return (pipes[index_cmd][1]);
}

int	close_unused_fds(int **pipes, int index_cmd, int commands_size)
{
	int	fd_in;
	int	fd_out;
	int	i;
	int	err;

	i = 0;
	fd_in = get_fd_in(pipes, index_cmd);
	fd_out = get_fd_out(pipes, index_cmd, commands_size);
	while (i < commands_size - 1)
	{
		if (pipes[i][0] != fd_in)
		{
			if (close(pipes[i][0]) == -1)
				return (1);
		}
		if (pipes[i][1] != fd_out)
		{
			if (close(pipes[i][1]) == -1)
				return (1); // TODO deal with return
		}
		i++;
	}
	return (0);	
}

int	pipes_get_size(int **pipes)
{
	int	i;

	i = 0;
	if (!pipes)
		return (0);
	while (pipes[i])
		i++;
	return (i);
}
