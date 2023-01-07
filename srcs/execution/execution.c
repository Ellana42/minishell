#include "execution.h"

int	execution_finish(t_execution *execution, int err)
{
	execution_close(execution);
	execution_destroy(execution);
	return (err);
}

int	execution_wait_processes(t_execution *execution)
{
	int	status;
	int	pid;

	(void )execution;
	status = 0;
	pid = 0;
	while (pid != -1 || errno != ECHILD)
	{
		pid = waitpid(-1, &status, 0);
		if (WIFSIGNALED(status))
			status = 128 + WTERMSIG(status);
		else if (WIFEXITED(status))
			status = WEXITSTATUS(status);
		if (status == 130 && pid != -1)
			printf("\n");
		if (pid == execution->last_pid)
		{
			if (glob_get_exit_status() == -5)
				glob_set_exit_status(130);
			else
				glob_set_exit_status(status);
		}
		continue ;
	}
	return (status);
}

int	execution_simple(t_execution *execution)
{
	int	i;
	int	exit_status;

	i = 0;
	while (i < execution->executables_size)
	{
		if (execution_is_command(execution))
		{
			if (execution_fork_process(execution))
				return (execution_finish(execution, 1));
		}
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
	if (execution->executables_size == 0)
		return (0);
	if (!execution_is_command(execution))
		return (0);
	if (execution_is_builtin(execution))
		return (1);
	return (0);
}

int	execution(t_parser *parser, t_minishell *minishell)
{
	t_execution		*execution;
	int				exit_status;

	execution = execution_alloc();
	if (execution_init(execution, parser, minishell))
		return (execution_finish(execution, 1));
	if (execution_is_single_builtin(execution))
		exit_status = execution_launch_builtin_single(execution);
	else
		exit_status = execution_simple(execution);
	execution_destroy(execution);
	return (exit_status);
}
