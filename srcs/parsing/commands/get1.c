#include "commands.h"

int	commands_get_size(t_commands *commands)
{
	if (!commands)
		return (-1);
	return (ft_lstsize(*commands));
}
