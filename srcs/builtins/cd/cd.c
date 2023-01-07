/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellana <mtmrkaploun@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:02:45 by ellana            #+#    #+#             */
/*   Updated: 2023/01/07 11:54:02 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cd.h"

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
	int		err;

	err = 0;
	ret = NULL;
	if (chdir(path) != 0)
		return (error_msg2("cd", path, strerror(errno), errno));
	ret = getcwd(cwd, PATH_MAX);
	if (!ret)
	{
		error_msg("cd", "error retrieving current directory", 0);
		error_msg2("getcwd", \
				"error retrieving current directory", strerror(errno), 0);
		ret = ft_strjoin(glob_getenv_var("PWD"), "/");
		tmp = ret;
		ret = ft_strjoin(tmp, path);
		free(tmp);
		err = 1;
	}
	else
		ret = ft_strdup(cwd);
	update_wd(ret);
	return (err);
}

int	cd_check_args(char **args_table)
{
	if (table_get_size(args_table) > 2)
	{
		error_msg("cd", "too many arguments", 0);
		return (1);
	}
	if (table_get_size(args_table) == 1)
	{
		error_msg("cd", "No path provided", 0);
		return (1);
	}
	if (!path_exists(args_table[1]))
	{
		error_msg2("cd", args_table[1], "No such file or directory", 0);
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
