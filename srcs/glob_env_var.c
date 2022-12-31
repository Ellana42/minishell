#include "glob.h"

int	glob_env_has_var(char *var)
{
	int		i;
	int		env_size;

	i = 0;
	env_size = ft_lstsize(*glob_get_env());
	while (i < env_size)
	{
		if (str_are_equal(glob_env_get_key_i(i), var) == 1)
			return (1);
		i++;
	}
	return (0);
}

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
	if (new_value)
		line_env->value = ft_strdup(new_value);
	else
		line_env->value = NULL;
	return (0);
}

int	glob_remove_var(char *var)
{
	int		index_line_var;
	t_list	*line_env;
	t_list	*previous_line_env;
	t_list	**current_env;

	index_line_var = glob_getenv_var_index(var);
	if (index_line_var == -1)
		return (0);
	current_env = glob_get_env();
	line_env = lst_get_i_lst(*current_env, index_line_var);
	if (index_line_var == 0)
	{
		*current_env = line_env->next;
		glob_set_env(current_env);
	}
	else
	{
		previous_line_env = lst_get_i_lst(*current_env, index_line_var - 1);
		previous_line_env->next = line_env->next;
	}
	env_el_destroy(line_env->content);
	free(line_env);
	return (0);
}
