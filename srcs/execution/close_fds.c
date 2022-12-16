#include "execution.h"

int	execution_close_all_pipes(t_execution *execution)
{
	int	i;

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

	i = 0;
	while (i < execution->executables_size - 1)
	{
		if (i != index - 1 && i != index)
		{
			if (close_pipe(execution->pipes[i][0], execution->pipes[i][1]))
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
				return (1);
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
			return (1);
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
