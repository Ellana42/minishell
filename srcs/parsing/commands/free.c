#include "commands.h"

void	commands_dispose(t_commands *commands)
{
	ft_lstclear(commands, &_free_command);
}

void	commands_free(t_commands *commands)
{
	free(commands);
}

void	commands_destroy(t_commands *commands)
{
	commands_dispose(commands);
	commands_free(commands);
}
