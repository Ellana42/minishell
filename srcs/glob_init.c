#include "glob.h"

extern t_glob	*g_glob;

int	glob_init(int error, char **envp)
{
	g_glob = (t_glob *)malloc(sizeof(t_glob));
	if (!g_glob)
		return (1);
	g_glob->activated = 1;
	g_glob->exit_status = error;
	g_glob->pids = (t_intlist ***)malloc(sizeof(t_intlist **));
	if (!g_glob->pids)
		return (1);
	g_glob->env = (char ***)malloc(sizeof(char **));
	if (!g_glob->env)
		return (1);
	*g_glob->pids = NULL;
	*g_glob->env = realloc_env_vars(envp);
	if (!*g_glob->env)
		return (1);
	return (0);
}

void	glob_destroy(void)
{
	table_free(*g_glob->env);
	free(g_glob->env);
	free(g_glob->pids);
	free(g_glob);
}
