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
