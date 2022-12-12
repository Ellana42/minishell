#include "command.h"

void	_free_string(void *str)
{
	free(str);
}

void	_free_funnel(void *funnel)
{
	t_funnel	*tmp;
	
	tmp = (t_funnel *)funnel;
	free(tmp->filename);
	free(tmp);
}

void	command_dispose(t_command *command)
{
	free(command->command);
	ft_lstclear(command->args, &_free_string);
	ft_lstclear(command->out, &_free_funnel);
	ft_lstclear(command->out_a, &_free_string);
	ft_lstclear(command->in, &_free_string);
	ft_lstclear(command->in_a, &_free_string);
	free(command->args);
	free(command->out);
	free(command->out_a);
	free(command->in);
	free(command->in_a);
}

void	command_free(t_command *command)
{
	free(command);
}

void	command_destroy(t_command *command)
{
	command_dispose(command);
	command_free(command);
}
