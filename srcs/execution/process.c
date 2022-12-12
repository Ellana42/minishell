/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:14:58 by lsalin            #+#    #+#             */
/*   Updated: 2022/12/12 14:36:54 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	launch_child(t_data data, t_command *cmd, int fd[2])
{
	int	pid;
	int	error;
	pid = fork();

	if (pid == -1)
		return (1);
		 // TODO deal with this

	// TODO deals with pipes

	if (fd[0] != -1 && fd[0] != -2)
		dup2(fd[0], STDIN_FILENO);

	if (fd[1] != -1 && fd[1] != -2)
		dup2(fd[1], STDOUT_FILENO);

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
	char		*args_table;

	path = get_user_cmd(command_get_name(cmd), &data);

	if (execve(path, command_get_args_table(cmd), data.envp) == 0)
		return (1); // TODO deal with this
	return (0);
}
