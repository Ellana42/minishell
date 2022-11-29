/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:45:04 by lsalin            #+#    #+#             */
/*   Updated: 2022/10/06 11:43:14 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*find_path(char *cmd, char **envp)
{
	char		**array_of_paths;
	char		*path_ultime;
	int			i;
	char		*temp;

	i = 0;
	while (ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	array_of_paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (array_of_paths[i])
	{
		temp = ft_strjoin(array_of_paths[i], "/");
		path_ultime = ft_strjoin(temp, cmd);
		free_strs(temp, NULL);
		if (access(path_ultime, F_OK | X_OK) == 0)
		{
			free_strs(NULL, array_of_paths);
			return (path_ultime);
		}
		free_strs(path_ultime, NULL);
		i++;
	}
	free_strs(NULL, array_of_paths);
	return (0);
}
