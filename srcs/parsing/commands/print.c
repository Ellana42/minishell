#include "commands.h"

void	_command_print(void *command)
{
	command_print((t_command *)command);
}

void	commands_print(t_commands *commands)
{
	ft_lstiter(*commands, &_command_print);
}
