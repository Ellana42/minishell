#include "command.h"

char	*_new_str(char *str)
{
	char	*tmp;
	size_t	size;

	size = ft_strlen(str);
	tmp = (char *)malloc(sizeof(char) * (size + 1));
	str_cpy(tmp, str);
	return (tmp);
}

int	command_add_arg(t_command *command, char *str)
{
	char	*tmp;

	tmp = _new_str(str); 
	if (!tmp)
		return (1);
	ft_lstadd_back(command->args, ft_lstnew(tmp));
	return (0);
}

int	command_add_out(t_command *command, char *str)
{
	char	*tmp;

	tmp = _new_str(str); 
	if (!tmp)
		return (1);
	ft_lstadd_back(command->out, ft_lstnew(tmp));
	return (0);
}

int	command_add_out_a(t_command *command, char *str)
{
	char	*tmp;

	tmp = _new_str(str); 
	if (!tmp)
		return (1);
	ft_lstadd_back(command->out_a, ft_lstnew(tmp));
	return (0);
}

int	command_add_in(t_command *command, char *str)
{
	char	*tmp;

	tmp = _new_str(str); 
	if (!tmp)
		return (1);
	ft_lstadd_back(command->in, ft_lstnew(tmp));
	return (0);
}

int	command_add_in_a(t_command *command, char *str)
{
	char	*tmp;

	tmp = _new_str(str); 
	if (!tmp)
		return (1);
	ft_lstadd_back(command->in_a, ft_lstnew(tmp));
	return (0);
}
