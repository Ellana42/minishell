#include "execution.h"

int	execution_is_builtin(t_execution *execution)
{
	char	*command_name;

	command_name = command_get_name(execution_get_current_command(execution));
	if (!ft_strncmp(command_name, "echo", 5))
		return (1);
	if (!ft_strncmp(command_name, "exit", 5))
		return (2);
	return (0);
}

int	execution_launch_builtin(t_execution *execution)
{
	int			command_number;
	t_command	*command;
	char		**args_table;
	int			err;

	command_number = execution_is_builtin(execution);
	command = execution_get_current_command(execution);
	args_table = command_get_args_table(command);
	err = 0;
	if (command_number == 1)
		err = echo(args_table);
	if (command_number == 2)
		err = builtin_exit(args_table);
	table_free(args_table);
	return (err);
}
