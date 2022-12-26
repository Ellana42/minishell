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

char	**glob_get_env(void)
{
	return (*(g_glob->env));
}

t_intlist	**glob_get_pids(void)
{
	return (*g_glob->pids);
}
