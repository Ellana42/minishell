#include "export.h"

int	str_store(char **dst, char *src, int start, int end)
{
	int	i;

	i = start;
	*dst = NULL;
	if (start > end)
		return (1);
	if (end > ft_strlen(src))
		return (1);
	*dst = (char *)malloc(sizeof(char) * (end - start + 1));
	while (i < end)
	{
		(*dst)[i - start] = src[i];
		i++;
	}
	return (0);
}

void	export_arg_free(t_export_arg export_arg)
{
	free(export_arg.variable);
	free(export_arg.value);
}

void	export_arg_print(t_export_arg export_arg)
{
	printf("variable :%s:\n", export_arg.variable);
	if (export_arg.operator_ == 0)
		printf("operator =\n");
	if (export_arg.operator_ == 1)
		printf("operator +=\n");
	printf("value :%s:\n", export_arg.value);
}

int	export_parse_arg(char *arg, t_export_arg *export_arg)
{
	int		i;

	i = 0;
	while (ft_isalnum(arg[i]) || arg[i] == '_')
		i++;
	str_store(&(export_arg->variable), arg, 0, i);
	if (arg[i] == '=')
		export_arg->operator_ = 0;
	else if (arg[i] == '+')
		export_arg->operator_ = 1;
	else
		return (1);
	i++;
	if (export_arg->operator_ == 1 && arg[i] != '=')
		return (1);
	if (export_arg->operator_ == 1)
		i++;
	str_store(&(export_arg->value), arg, i, ft_strlen(arg));
	return (0);
}

int	builtin_export(char **args_table)
{
	t_export_arg	arg;

	arg.value = NULL;
	arg.variable = NULL;
	arg.operator_ = 2;
	printf("Argument : %s\n", args_table[1]);
	if (export_parse_arg(args_table[1], &arg))
	{
		printf("Export arg parsing error\n");
		export_arg_free(arg);
		return (1);
	}
	export_arg_print(arg);
	export_arg_free(arg);
	return (0);
}
