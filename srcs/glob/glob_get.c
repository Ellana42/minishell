#include "glob.h"

extern t_glob	*g_glob;

int	glob_get_last_pid(void)
{
	t_intlist	*lst;

	if (!glob_get_pids())
		return (-1);
	if (!*glob_get_pids())
		return (-1);
	lst = intlstlast(*glob_get_pids());
	if (!lst)
		return (-1);
	return (lst->content);
}

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

t_intlist	**glob_get_pids(void)
{
	return (*g_glob->pids);
}
