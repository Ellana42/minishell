#include "execution.h"

int	execution_launch_exec(t_execution *execution)
{
	char		*path;
	char		*args_table;
	t_command	*command;
	char		**env;

	command = execution_get_current_command(execution);
	env = execution_get_env(execution);
	path = get_user_cmd(command_get_name(command), env);
	if (!path)
		return (1);
	if (execve(path, command_get_args_table(command), env) == 0)
		return (1);
	return (0);
}

int	execution_child(t_execution *execution)
{
	t_executable	*executable;
	int				fd[2];
	int				err;

	err = 0;
	executable = execution_get_current(execution);
	executable_get_fds_close(executable, fd);
	execution_close_unused(execution, execution->executable_index);
	if (execution_dup_in(fd[0]))
		return (1);
	if (execution_dup_out(fd[1]))
		return (1);
	err = execution_launch_exec(execution);
	close_fd(fd[0]);
	close_fd(fd[1]);
	return (err);
}

int	execution_fork_process(t_execution *execution)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		if (execution_child(execution))
			return (1);
	}
	else
		execution_store_pid(execution, pid);
	return (0);
}
