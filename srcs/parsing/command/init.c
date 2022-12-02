#include "command.h"

t_command	*command_alloc(void)
{
	t_command	*command;

	command = (t_command *)malloc(sizeof(t_command));
	return (command);
}

int	command_init(t_command *command, char *cmd)
{
	char	*cmd_cpy;

	cmd_cpy = (char *)malloc(sizeof(char) * (ft_strlen(cmd) + 1));
	str_cpy(cmd, cmd_cpy);
	command->command = cmd_cpy;
	command->args = ft_lstinit();
	command->out = ft_lstinit();
	command->out_a = ft_lstinit();
	command->in = ft_lstinit();
	command->in_a = ft_lstinit();
	return (0); // errors
}

void	_free_string(void *str)
{
	free(str);	
}

void command_dispose(t_command *command)
{
	free(command->command);
	ft_lstclear(command->args, &_free_string);
	ft_lstclear(command->out, &_free_string);
	ft_lstclear(command->out_a, &_free_string);
	ft_lstclear(command->in, &_free_string);
	ft_lstclear(command->in_a, &_free_string);
	free(command->args);
	free(command->out);
	free(command->out_a);
	free(command->in);
	free(command->in_a);
}

void command_free(t_command *command)
{
	free(command);
}

void	command_destroy(t_command *command)
{
	command_dispose(command);
	command_free(command);
}
