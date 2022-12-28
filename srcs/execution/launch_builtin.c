#include "execution.h"

int	execution_is_builtin(t_execution *execution)
{
	char	*command_name;

	command_name = command_get_name(execution_get_current_command(execution));
	if (!ft_strncmp(command_name, "echo", 5))
		return (1);
	if (!ft_strncmp(command_name, "exit", 5))
		return (2);
	if (!ft_strncmp(command_name, "env", 4))
		return (3);
	if (!ft_strncmp(command_name, "cd", 3))
		return (4);
	if (!ft_strncmp(command_name, "pwd", 4))
		return (5);
	if (!ft_strncmp(command_name, "export", 7))
		return (6);
	if (!ft_strncmp(command_name, "unset", 6))
		return (7);
	return (0);
}

int	call_builtin(char **args_table, int command_number)
{
	int			err;

	err = 0;
	if (command_number == 1)
		err = echo(args_table);
	if (command_number == 2)
		err = builtin_exit(args_table);
	if (command_number == 3)
		err = env(args_table);
	/* if (command_number == 4) */
	/* 	err = cd(args_table); */
	/* if (command_number == 5) */
	/* 	err = pwd(args_table); */
	/* if (command_number == 6) */
	/* 	err = export(args_table); */
	if (command_number == 7)
		err = unset(args_table);
	return (err);
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
	err = call_builtin(args_table, command_number);
	if (!execution_is_single_builtin(execution))
		table_free(args_table);
	else
		free(args_table);
	return (err);
}
