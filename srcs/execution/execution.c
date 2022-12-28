#include "execution.h"

int	execution_finish(t_execution *execution, int err)
{
	execution_close(execution);
	execution_destroy(execution);
	return (err);
}

int	execution_wait_processes(t_execution *execution)
{
	int	exit_status;
	int	i;
	int	pid;

	exit_status = 0;
	i = 0;
	pid = -1;
	while (i < execution->executables_size)
	{
		pid = execution_get_pid(execution);
		if (pid != -1)
		{
			waitpid(pid, &exit_status, 0);
			if (WIFEXITED(exit_status))
				exit_status = WEXITSTATUS(exit_status);
		}
		i++;
	}
	return (exit_status);
}

int	execution_simple(t_execution *execution)
{
	int	i;
	int	exit_status;

	i = 0;
	while (i < execution->executables_size)
	{
		if (execution_fork_process(execution))
			return (execution_finish(execution, 1));
		execution_move(execution);
		i++;
	}
	execution_close(execution);
	exit_status = execution_wait_processes(execution);
	return (exit_status);
}

int	execution_is_single_builtin(t_execution *execution)
{
	if (execution->executables_size > 1)
		return (0);
	if (execution_is_builtin(execution))
		return (1);
	return (0);
}

// TODO deal with close error ?
int	execution(t_commands *commands, char **envp)
{
	t_execution		*execution;
	t_executable	*executable;
	int				i;
	int				pid;
	int				exit_status;

	i = 0;
	execution = execution_alloc();
	if (execution_init(execution, commands, envp))
		return (execution_finish(execution, 1));
	if (execution_is_single_builtin(execution))
		exit_status = execution_launch_builtin(execution);
	else
		exit_status = execution_simple(execution);
	execution_destroy(execution);
	if (glob_get_exit_status() == -5)
		return (130);
	return (exit_status);
}
