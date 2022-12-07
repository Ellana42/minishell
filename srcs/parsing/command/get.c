#include "command.h"

char	*command_get_name(t_command *command)
{
	return (command->command);
}

t_list	**command_get_args(t_command *command)
{
	return (command->args);
}

t_list	**command_get_out(t_command *command)
{
	return (command->out);
}

t_list	**command_get_outa(t_command *command)
{
	return (command->out_a);
}

t_list	**command_get_in(t_command *command)
{
	return (command->in);
}

t_list	**command_get_ina(t_command *command)
{
	return (command->in_a);
}

char	**command_get_args_table(t_command *command)
{
	size_t	size_args;
	char	**table;
	int		i;

	i = 1;
	size_args = ft_lstsize(*command->args) + 1;
	table = (char **)malloc(sizeof(char *) * (size_args + 2));
	table[0] = command_get_name(command);
	while (i < size_args)
	{
		table[i] = lst_get_i(*command_get_args(command), i);
		i++;
	}
	return (table);
}
