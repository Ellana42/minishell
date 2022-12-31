#include "export.h"

void	export_el_print(void *content)
{
	t_dict	*dict;

	dict = (t_dict *)content;
	printf("declare -x ");
	printf("%s", dict->key);
	if (dict->value)
		printf("=\"%s\"\n", dict->value);
	else
		printf("\n");
}

void	export_print(void)
{
	ft_lstiter(*glob_get_env(), &export_el_print);
}

int	export_push_var(char *var, char *val)
{
	printf("Push var\n");
	if (glob_getenv_var(var))
		glob_env_replace_var(var, val);
	else
		glob_env_add_line(var, val);
	return (0);
}

int	export_append_var(char *var, char *val)
{
	char	*new_value;

	printf("Append var\n");
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
		printf("bash: export: memory error\n");
		export_arg_free(arg);
		return (1);
	}
	else if (err == 1)
		printf("bash: export: `%s': not a valid identifier\n", argument);
	else if (arg.operator_ == 0)
		export_push_var(arg.variable, arg.value);
	else
		export_append_var(arg.variable, arg.value);
	export_arg_free(arg);
	return (0);
}

int	builtin_export(char **args_table)
{
	int	size;
	int	i;

	i = 1;
	size = table_get_size(args_table);
	if (size == 1)
		export_print();
	while (i < size)
	{
		if (export_one_var(args_table[i]))
			return (1);
		i++;
	}
	return (0);
}
