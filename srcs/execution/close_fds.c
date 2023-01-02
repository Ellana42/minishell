/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellana <mtmrkaploun@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:09:13 by ellana            #+#    #+#             */
/*   Updated: 2023/01/02 18:09:30 by ellana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	execution_close_all_pipes(t_execution *execution)
{
	int	i;

	i = 0;
	while (i < execution->executables_size - 1)
	{
		if (close_fd(execution->pipes[i][0]))
			return (1);
		if (close_fd(execution->pipes[i][1]))
			return (1);
		i++;
	}
	return (0);
}

int	execution_close_all_files(t_execution *execution)
{
	int				i;
	t_executable	*executable;

	i = 0;
	while (i < execution->executables_size)
	{
		executable = execution_get_executable_i(execution, i);
		if (executable_close_files(executable))
			return (1);
		i++;
	}
	return (0);
}

int	execution_close(t_execution *execution)
{
	if (execution_close_all_pipes(execution))
		return (1);
	if (execution_close_all_files(execution))
		return (1);
	return (0);
}
