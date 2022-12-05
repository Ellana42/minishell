#include "command.h"

int	command_add_in_a(t_command *command, char *str)
{
	char	*tmp;

	tmp = _new_str(str);
	if (!tmp)
		return (1);
	ft_lstadd_back(command->in_a, ft_lstnew(tmp));
	return (0);
}
