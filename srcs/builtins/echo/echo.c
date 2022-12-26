#include "echo.h"

int	is_flag(char *arg)
{
	if (!arg)
		return (1);
	return (ft_strncmp(arg, "-n", 3));
}

int	looks_like_flag(char *arg)
{
	int	i;

	i = 0;
	if (!arg)
		return (0);
	if (ft_strlen(arg) < 2)
		return (0);
	if (ft_strncmp(arg, "-n", 2))
		return (0);
	i = 1;
	while (arg[i] == 'n')
		i++;
	return (arg[i] == '\0');
}

int	get_flags(char **args, int *n)
{
	int		i;

	i = 1;
	while (looks_like_flag(args[i]))
	{
		*n = 1;
		i++;
	}
	return (i);
}

int	echo(char **args)
{
	int		i;
	size_t	size;
	int		n;

	i = 1;
	n = 0;
	if (!args)
		return (1);
	size = table_get_size(args);
	if (size <= 1)
	{
		printf("\n");
		return (0);
	}
	i = get_flags(args, &n);
	while (i < size - 1)
	{
		printf("%s ", args[i]);
		i++;
	}
	if (i == size - 1)
		printf("%s", args[i]);
	if (!n)
		printf("\n");
	return (0);
}
