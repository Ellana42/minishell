/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:14:58 by lsalin            #+#    #+#             */
/*   Updated: 2022/12/10 17:34:43 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	launch_child(t_data data, t_command *cmd, int fd)
{
	int	pid;
	int	error;
	pid = fork();

	if (pid == -1)
		return (1); // TODO deal with this

	// TODO deals with pipes

	if (fd != -1)
		dup2(fd, STDOUT_FILENO);

	if (pid == 0)
	{
		error = launch_cmd(data, cmd);
		if (error)
			return (error);
	}
	return (0);
}

int	launch_cmd(t_data data, t_command *cmd)
{
	char		*path;

	path = get_user_cmd(command_get_name(cmd), &data);

	if (execve(path, command_get_args_table(cmd), data.envp) == -1)
		return (1); // TODO deal with this

	return (0);
}