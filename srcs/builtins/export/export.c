#include "export.h"

/* int	export_add_var_to_env(t_export_arg *arg) */
/* { */
/* 	char	**old_env; */
/* 	char	**new_env; */

/* 	old_env = glob_get_env(); */
/* 	if (arg->operator_ == 0) */
/* 		table_add_line(&old_env, arg->full_arg); */
/* 	return (0); */
/* } */

void	export_el_print(void *content)
{
	t_dict	*dict;

	dict = (t_dict *)content;
	printf("declare -x ");
	printf("%s", dict->key);
	if (dict->value)
		printf("=\"%s\"\n", dict->value);
}

void	export_print(void)
{
	ft_lstiter(*glob_get_env(), &export_el_print);
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
	printf("Argument : %s\n", argument);
	err = export_parse_arg(argument, &arg);
	if (err == 2)
	{
		printf("bash: export: memory error\n");
		export_arg_free(arg);
		return (1);
	}
	else if (err == 1)
		printf("bash: export: `%s': not a valid identifier\n", argument);
	else
		export_arg_print(arg);
	export_arg_free(arg);
	return (0);
}

int	builtin_export(char **args_table)
{
	int	size;
	int	i;

	i = 1;
	size = table_get_size(args_table);
	if (size == 0)
		export_print();
	while (i < size)
	{
		if (export_one_var(args_table[i]))
			return (1);
		i++;
	}
	return (0);
}
