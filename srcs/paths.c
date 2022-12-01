/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:45:04 by lsalin            #+#    #+#             */
/*   Updated: 2022/12/01 20:46:25 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_path(t_data *data)
{
	char		**array_of_paths;
	char		*path_ultime;
	int			i;
	char		*temp;

	i = 0;
	while (ft_strnstr(data->envp[i], "PATH=", 5) == 0)
		i++;
	array_of_paths = ft_split(data->envp[i] + 5, ':');
	i = 0;
	while (array_of_paths[i])
	{
		temp = ft_strjoin(array_of_paths[i], "/");
		path_ultime = ft_strjoin(temp, data->cmd);
		free_strs(temp, NULL, NULL);
		if (access(path_ultime, F_OK | X_OK) == 0)
		{
			free_strs(NULL, array_of_paths, NULL);
			return (path_ultime);
		}
		free_strs(path_ultime, NULL, NULL);
		i++;
	}
	free_strs(NULL, array_of_paths, NULL);
	return (0);
}
