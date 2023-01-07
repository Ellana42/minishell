/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellana <mtmrkaploun@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:02:45 by ellana            #+#    #+#             */
/*   Updated: 2023/01/07 11:54:02 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "export.h"

int	export_push_var(char *var, char *val)
{
	if (glob_env_has_var(var))
	{
		if (val)
			glob_env_replace_var(var, val);
	}
	else
		glob_env_add_line(var, val);
	return (0);
}

int	export_append_var(char *var, char *val)
{
	char	*new_value;

	if (glob_getenv_var(var))
	{
		new_value = ft_strjoin(glob_getenv_var(var), val);
		if (!new_value)
			return (1);
		glob_env_replace_var(var, new_value);
		free(new_value);
	}
	else
		glob_env_add_line(var, val);
	return (0);
}

int	export_one_var(char *argument)
{
	t_export_arg	arg;
	int				err;

	arg.full_arg = ft_strdup(argument);
	if (!arg.full_arg)
		return (1);
	arg.value = NULL;
	arg.variable = NULL;
	arg.operator_ = 2;
	err = export_parse_arg(argument, &arg);
	if (err == 2)
	{
		error_msg("export", "memory error", 0);
		export_arg_free(arg);
		return (1);
	}
	else if (err == 1)
		error_msg2("export", argument, "not a valid identifier", 0);
	else if (arg.operator_ == 1)
		export_append_var(arg.variable, arg.value);
	else
		export_push_var(arg.variable, arg.value);
	export_arg_free(arg);
	return (err);
}

int	builtin_export(char **args_table)
{
	int	size;
	int	i;
	int	ret;

	i = 1;
	ret = 0;
	size = table_get_size(args_table);
	if (size == 1)
		export_print();
	while (i < size)
	{
		if (ret == 0)
			ret = export_one_var(args_table[i]);
		else
			export_one_var(args_table[i]);
		i++;
	}
	return (ret);
}
