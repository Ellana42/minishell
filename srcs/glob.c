#include "glob.h"

extern t_glob *g_glob;

int	glob_init()
{
	g_glob = (t_glob *)malloc(sizeof(t_glob));
	if (!g_glob)
		return (1);
	g_glob->activated = 1;
	g_glob->pids = NULL;
	return (0);
}

int	glob_get_state()
{
	return (g_glob->activated);
}

void	glob_print()
{
	printf("Glob : \n");
	printf("Activated : %d\n", glob_get_state());
	printf("Pids : ");
	/* while () */
}
