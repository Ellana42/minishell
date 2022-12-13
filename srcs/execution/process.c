/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:14:58 by lsalin            #+#    #+#             */
/*   Updated: 2022/12/13 15:57:33 by mkaploun         ###   ########.fr       */
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

	if (pid == 0)
	{

		printf("cmd : %s subprocess\n", command_get_name(cmd));
		if (fd[0] != -1 && fd[0] != -2)
		{
			printf("cmd : %s redirige %d vers stdin\n", command_get_name(cmd), fd[0]);
			if (dup2(fd[0], STDIN_FILENO) == -1)
				printf("Issue with dup2 in\n");
		}

		if (fd[1] != -1 && fd[1] != -2)
		{
			printf("cmd : %s redirige %d vers stdout\n", command_get_name(cmd), fd[1]);
			if (dup2(fd[1], STDOUT_FILENO) == -1) // TODO deals with dup2() errors
				printf("Issue with dup2 out\n");
		}

		error = launch_cmd(data, cmd);
		if (error)
			return (error);
	}
	/* if (fd[0] >= 0) */
	/* 	close(fd[0]); */
	/* if (fd[1] >= 0) */
	/* 	close(fd[1]); */
	return (0);
}

int	launch_cmd(t_data data, t_command *cmd)
{
	char	*path;
	char	*args_table;

	printf("%s Got here\n", command_get_name(cmd));
	path = get_user_cmd(command_get_name(cmd), &data);
	printf("%s Got there\n", command_get_name(cmd));

	if (execve(path, command_get_args_table(cmd), data.envp) == 0)
	{
		printf("issue\n");
		return (1); // TODO deal with this
	}
	printf("FINISH\n");
	return (0);
}
