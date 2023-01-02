#include "exit.h"

extern t_glob	*g_glob;

int	is_numeric(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	exit_parse_args(char **args, int *err_num)
{
	if (table_get_size(args) > 2)
	{
		printf("minishell: exit: too many arguments\n");
		return (1);
	}
	if (table_get_size(args) == 1)
		return (0);
	if (!is_numeric(args[1]))
	{
		*err_num = 2;
		printf("minishell: exit: %s: numeric argument required\n", args[1]);
		return (0);
	}
	if (long_long_atoi(args[1], (long long *)err_num))
		printf("minishell: exit: %s: numeric argument required\n", args[1]);
	return (0);
}

int	builtin_exit(char **args)
{
	int	err_num;

	err_num = 0;
	printf("exit\n");
	if (exit_parse_args(args, &err_num))
		return (1);
	glob_set_state(0);
	return (err_num);
}
