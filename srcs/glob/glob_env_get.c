/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob_env_get.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:52:39 by mkaploun          #+#    #+#             */
/*   Updated: 2023/01/07 11:52:45 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	key = glob_env_get_key_i(i);
	value = glob_env_get_val_i(i);
	if (!value)
		return (NULL);
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
	char	*line;

	i = 0;
	env_size = ft_lstsize(*glob_get_env());
	env_table = (char **)malloc(sizeof(char *) * (env_size + 1));
	if (!env_table)
		return (NULL);
	while (i < env_size)
	{
		line = glob_get_env_line_i(i);
		if (line)
			env_table[i] = line;
		i++;
	}
	env_table[i] = NULL;
	return (env_table);
}
