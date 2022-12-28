#include "glob.h"

extern t_glob	*g_glob;

char	*glob_getenv_var(char *var)
{
	char	**env;
	int		i;
	char	**split_var;
	char	*value;

	i = 0;
	env = glob_get_env();
	while (env[i])
	{
		split_var = ft_split(env[i], '=');
		if (!split_var)
			return (NULL);
		if (str_are_equal(split_var[0], var) == 1)
		{
			value = ft_strdup(split_var[1]);
			table_free(split_var);
			return (value);
		}
		table_free(split_var);
		i++;
	}
	return (NULL);
}

int	glob_pop_pid(int *pid)
{
	if (!*g_glob->pids)
		return (1);
	return (intlst_pop(*g_glob->pids, pid));
}

int	glob_is_running(void)
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
