#include "glob.h"

extern t_glob *g_glob;

int	glob_init()
{
	g_glob = (t_glob *)malloc(sizeof(t_glob));
	if (!g_glob)
		return (1);
	g_glob->activated = 1;
	g_glob->pids = (t_intlist ***)malloc(sizeof(t_intlist **));
	if (!g_glob->pids)
		return (1);
	*g_glob->pids = NULL;
	return (0);
}

void	glob_destroy()
{
	free(g_glob->pids);
	free(g_glob);
}

int	glob_get_state()
{
	return (g_glob->activated);
}

t_intlist	**glob_get_pids()
{
	return (*g_glob->pids);
}

void	glob_set_pids(t_intlist **pids)
{
	*g_glob->pids = pids;
}

int	glob_pop_pid(int *pid)
{
	if (!*g_glob->pids)
		return (1);
	return (intlst_pop(*g_glob->pids, pid));
}

void	glob_print()
{
	printf("Glob : \n");
	printf("Activated : %d\n", glob_get_state());
	if (glob_get_pids())
	{
		printf("Pids : ");
		int_lstprint(*glob_get_pids());
	}
}
