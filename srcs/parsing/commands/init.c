#include "commands.h"

t_commands	*commands_alloc(void)
{
	t_commands	*commands;

	commands = ft_lstinit();
	return (commands);
}

int	commands_init(t_commands *commands)
{
	return (0);
}

void	_free_command(void *command)
{
	command_destroy((t_command *)command);
}

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
