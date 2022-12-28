#include "exit.h"

extern t_glob	*g_glob;

int	builtin_exit(char **args)
{
	glob_set_state(0);
	return (0);
}
