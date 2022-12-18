#include "execution.h"

int	execution_close_all_pipes(t_execution *execution)
{
	int	i;
	int	size;

	i = 0;
	while (i < execution->executables_size - 1)
	{
		if (close_fd(execution->pipes[i][0]))
			return (1);
		if (close_fd(execution->pipes[i][1]))
			return (1);
		i++;
	}
	return (0);
}

int	execution_close_unused_pipes(t_execution *execution, int index)
{
	int	i;
	int	pipe[2];

	i = 0;
	while (i < execution->executables_size - 1)
	{
		if (i != index - 1 && i != index)
		{
			pipe[0] = execution->pipes[i][0];
			pipe[1] = execution->pipes[i][1];
			if (close_pipe(pipe))
				return (1);
		}
		i++;
	}
	return (0);
}

int	execution_close_unused_files(t_execution *execution, int index)
{
	int				i;
	t_executable	*executable;

	i = 0;
	while (i < execution->executables_size)
	{
		if (i != index)
		{
			executable = execution_get_executable_i(execution, i);
			if (executable_close_files(executable))
			{
				printf("Failiure in close unused files %d\n", i);
				return (1);
			}
		}
		i++;
	}
	return (0);
}

int	execution_close_all_files(t_execution *execution)
{
	int				i;
	t_executable	*executable;

	i = 0;
	while (i < execution->executables_size)
	{
		executable = execution_get_executable_i(execution, i);
		if (executable_close_files(executable))
		{
			printf("Failiure in close all files\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	execution_close_unused(t_execution *execution, int index)
{
	if (execution_close_unused_pipes(execution, index))
		return (1);
	if (execution_close_unused_files(execution, index))
		return (1);
	return (0);
}

int	execution_close(t_execution *execution)
{
	if (execution_close_all_pipes(execution))
		return (1);
	if (execution_close_all_files(execution))
		return (1);
	return (0);
}
