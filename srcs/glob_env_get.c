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
