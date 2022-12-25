#include "glob.h"

extern t_glob *g_glob;

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
	*g_glob->env = envp; // TODO change when integration with builtins
	return (0);
}

void	glob_destroy()
{
	free(g_glob->env); // TODO adapt to table
	free(g_glob->pids);
	free(g_glob);
}

int	glob_get_state()
{
	return (g_glob->activated);
}

int	glob_get_exit_status()
{
	return (g_glob->exit_status);
}

void	glob_set_exit_status(int exit_status)
{
	g_glob->exit_status = exit_status;
}

char **glob_get_env()
{
	return (*(g_glob->env));
}

void	glob_set_env(char **env)
{
	*(g_glob->env) = env;
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

int	glob_is_running()
{
	if (!glob_get_pids())
		return (0);
	if (!*glob_get_pids())
		return (0);
	return (1);
}

void	glob_print(t_bool print_env)
{
	printf("Glob : \n");
	printf("Activated : %d\n", glob_get_state());
	printf("Exit status : %d\n", glob_get_exit_status());
	if (glob_get_pids())
	{
		printf("Pids : ");
		int_lstprint(*glob_get_pids());
	}
	if (print_env)
		table_print(*(g_glob->env));
}
