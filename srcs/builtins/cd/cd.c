#include "cd.h"
#include <errno.h>

static void	update_wd(char *cwd)
{
	if (glob_env_has_var("OLDPWD"))
	{
		if (glob_env_has_var("PWD"))
			glob_env_replace_var("OLDPWD", glob_getenv_var("PWD"));
		else
			glob_env_replace_var("OLDPWD", cwd);
	}
	else
		glob_env_add_line("OLDPWD", cwd);
	if (glob_env_has_var("PWD"))
		glob_env_replace_var("PWD", cwd);
	else
		glob_env_add_line("PWD", cwd);
	free(cwd);
}

int	path_exists(char *path)
{
	struct stat	statbuf;

	if (stat(path, &statbuf) != 0)
		return (0);
	return (1);
}

static int	change_dir(char *path)
{
	char	*ret;
	char	*tmp;
	char	cwd[PATH_MAX];

	ret = NULL;
	if (chdir(path) != 0)
	{
		printf("minishell: cd: %s: %s\n", path, strerror(errno));
		return (errno);
	}
	ret = getcwd(cwd, PATH_MAX);
	if (!ret)
	{
		printf("cd: error retrieving current directory: ");
		printf("getcwd: cannot access parent directories: %s\n", strerror(errno));
		ret = ft_strjoin(glob_getenv_var("PWD"), "/");
		tmp = ret;
		ret = ft_strjoin(tmp, path);
		free(tmp);
	}
	else
		ret = ft_strdup(cwd);
	update_wd(ret);
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
	{
		printf("minishell: cd: No path provided\n");
		return (0);
	}
	if (!path_exists(args_table[1]))
	{
		printf("minishell: cd: %s: No such file or directory\n", args_table[1]);
		return (1);
	}
	return (change_dir(args_table[1]));
}

int	cd(char **args_table)
{
	if (cd_check_args(args_table))
		return (1);
	return (0);
}
