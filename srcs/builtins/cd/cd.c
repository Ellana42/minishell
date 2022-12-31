#include "cd.h"
#include <errno.h>

int	path_exists(char *path)
{
	struct stat	statbuf;

	if (stat(path, &statbuf) != 0)
		return (0);
	return (1);
}

int	cd_check_args(char **args_table)
{
	if (table_get_size(args_table) > 2)
	{
		printf("minishell: cd: too many arguments\n");
		return (1);
	}
	if (table_get_size(args_table) == 1)
		return (0);
	if (!path_exists(args_table[1]))
	{
		printf("minishell: cd: %s: No such file or directory\n", args_table[1]);
		return (1);
	}
	if (chdir(args_table[1]) != 0)
	{
		printf("minishell: cd: %s: %s\n", args_table[1], strerror(errno));
		return (errno);
	}
	return (0);
}

int	cd(char **args_table)
{
	if (cd_check_args(args_table))
		return (1);
	return (0);
}
