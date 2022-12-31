#include "glob.h"

t_dict	*glob_env_get_dict_i(int i)
{
	return ((t_dict *)lst_get_i(*glob_get_env(), i));
}

char	*glob_env_get_val_i(int i)
{
	t_dict	*dict;

	dict = glob_env_get_dict_i(i);
	if (!dict)
		return (NULL);
	return (dict->value);
}

char	*glob_env_get_key_i(int i)
{
	t_dict	*dict;

	dict = glob_env_get_dict_i(i);
	if (!dict)
		return (NULL);
	return (dict->key);
}

char	*glob_get_env_line_i(int i)
{
	char	*key;
	char	*value;
	char	*start_line;
	char	*full_line;
	int		len_line;

	key = glob_env_get_key_i(i);
	value = glob_env_get_val_i(i);
	len_line = ft_strlen(key) + ft_strlen(value) + 1;
	start_line = ft_strjoin(key, "=");
	if (!start_line)
		return (NULL);
	full_line = ft_strjoin(start_line, value);
	free(start_line);
	return (full_line);
}

char	**glob_env_get_table(void)
{
	int		i;
	int		env_size;
	char	**env_table;

	i = 0;
	env_size = ft_lstsize(*glob_get_env());
	env_table = (char **)malloc(sizeof(char *) * (env_size + 1));
	if (!env_table)
		return (NULL);
	while (i < env_size)
	{
		env_table[i] = glob_get_env_line_i(i);
		i++;
	}
	env_table[i] = NULL;
	return (env_table);
}
