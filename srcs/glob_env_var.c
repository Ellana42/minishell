#include "glob.h"

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

int	glob_getenv_var_index(char *var)
{
	int		i;
	int		env_size;

	i = 0;
	env_size = ft_lstsize(*glob_get_env());
	while (i < env_size)
	{
		if (str_are_equal(glob_env_get_key_i(i), var) == 1)
			return (i);
		i++;
	}
	return (-1);
}

int	glob_env_replace_var(char *var, char *new_value)
{
	int		index_line_var;
	t_dict	*line_env;

	index_line_var = glob_getenv_var_index(var);
	line_env = glob_env_get_dict_i(index_line_var);
	free(line_env->value);
	line_env->value = ft_strdup(new_value);
	return (0);
}
