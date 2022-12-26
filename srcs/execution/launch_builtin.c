#include "execution.h"

int	execution_is_builtin(t_execution *execution)
{
	char	*command_name;

	command_name = command_get_name(execution_get_current_command(execution));
	if (!ft_strncmp(command_name, "echo", 5))
		return (1);
	return (0);
}

int	execution_launch_builtin(t_execution *execution)
{
	int			command_number;
	t_command	*command;

	command_number = execution_is_builtin(execution);
	command = execution_get_current_command(execution);
	if (command_number == 1)
		return (echo(command_get_args_table(command)));
	return (0);
}
