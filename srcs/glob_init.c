#include "glob.h"

extern t_glob	*g_glob;

// Re-alloue de la memoire pour un nouvel env
// Retourne un pointeur sur le nouvel env ou NULL

char	**realloc_env_vars(char **envp)
{
	char	**new_env;
	int		i;

	new_env = (char **)malloc(sizeof(char *) * (table_get_size(envp) + 1));
	if (!new_env)
		return (NULL);
	i = 0;
	while (envp[i])
	{
		new_env[i] = ft_strdup(envp[i]);
		if (!new_env[i])
		{
			table_free(new_env);
			return (NULL);
		}
		i++;
	}
	new_env[i] = NULL;
	return (new_env);
}

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
