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

	if (execve(path, command_get_args_table(command), env) == 0)
		return (1); // TODO deal with this
	return (0);
}

int	execution_child(t_execution *execution)
{
	t_executable	*executable;
	int	fd[2];

	/* printf("Command : %s\n", command_get_name(execution_get_current_command(execution))); */
	executable = execution_get_current(execution); 
	executable_get_fds_close(executable, fd);
	execution_close_unused(execution, execution->executable_index);
	/* printf("Command : %s\n", command_get_name(execution_get_current_command(execution))); */
	/* printf("FD0 : %d, FD1 : %d\n", fd[0], fd[1]); */
	if (execution_dup_in(fd[0]))
		return (1);
	if (execution_dup_out(fd[1]))
		return (1);
	execution_launch_exec(execution);
	close(fd[0]);
	close(fd[1]);
	return (0);
}

int	execution_fork_process(t_execution *execution)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		return (1); // TODO deal with that
	if (pid == 0)
		execution_child(execution);
	else
		execution_store_pid(execution, pid);
	return (0);
}
