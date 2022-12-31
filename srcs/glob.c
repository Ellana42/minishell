#include "glob.h"

extern t_glob	*g_glob;

char	*glob_getenv_var(char *var)
{
	int		i;
	int		env_size;

	i = 0;
	env_size = ft_lstsize(*glob_get_env());
	while (i < env_size)
	{
		if (str_are_equal(glob_env_get_key_i(i), var) == 1)
			return (glob_env_get_val_i(i));
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
		env_print();
}
