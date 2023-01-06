#include "execution.h"

int	execution_is_command(t_execution *execution)
{
	if (command_get_name(execution_get_current_command(execution)))
		return (1);
	return (0);
}
