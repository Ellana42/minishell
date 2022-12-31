#include "export.h"

void	export_arg_free(t_export_arg export_arg)
{
	free(export_arg.full_arg);
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
	if (export_arg.operator_ == 2)
		printf("operator none\n");
	printf("value :%s:\n", export_arg.value);
}

int	export_parse_arg(char *arg, t_export_arg *export_arg)
{
	int		i;

	i = 0;
	while (ft_isalnum(arg[i]) || arg[i] == '_')
		i++;
	if (str_store(&(export_arg->variable), arg, 0, i))
		return (2);
	if (arg[i] == '=')
		export_arg->operator_ = 0;
	else if (arg[i] == '+')
		export_arg->operator_ = 1;
	else if (arg[i] == '\0')
		return (0);
	else
		return (1);
	i++;
	if (export_arg->operator_ == 1 && arg[i] != '=')
		return (1);
	if (export_arg->operator_ == 1)
		i++;
	if (str_store(&(export_arg->value), arg, i, ft_strlen(arg)))
		return (2);
	export_arg_print(*export_arg);
	return (0);
}
