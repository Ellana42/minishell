#include "glob.h"

extern t_glob	*g_glob;

int	glob_get_state(void)
{
	return (g_glob->activated);
}

int	glob_get_exit_status(void)
{
	return (g_glob->exit_status);
}

t_list	**glob_get_env(void)
{
	return (*(g_glob->env));
}
