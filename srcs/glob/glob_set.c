#include "glob.h"

extern t_glob	*g_glob;

void	glob_set_env(t_list **env)
{
	*(g_glob->env) = env;
}

void	glob_set_exit_status(int exit_status)
{
	g_glob->exit_status = exit_status;
}

void	glob_set_state(int state)
{
	g_glob->activated = state;
}
