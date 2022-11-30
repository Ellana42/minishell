/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:13:54 by lsalin            #+#    #+#             */
/*   Updated: 2022/11/30 13:12:06 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 0 --> stdin
// 1 --> stdout
// 2 --> stderr
// 3 --> file.txt

// 1 --> file.txt

#include "execution/pipe/pipex.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

// Echec valeur renvoie pas gere

int	redirections(t_command *command)
{
	int	pid;
	int	redirect_fd;
	int	redirect_fd;
	int	redirect_fd;
	pid = fork();

	if (pid == -1)
		return (1);

	if (pid == 0)
	{
		if (data->in) // '<'
		{
			redirect_fd = open("file.txt", O_RDONLY, 0);
			dup2(redirect_fd, STDIN_FILENO);
			close(redirect_fd);
		}

		else if (data->out) // '>'
		{
			redirect_fd = open("file.txt", O_CREAT | O_TRUNC);
			dup2(redirect_fd, STDOUT_FILENO);
			close(redirect_fd);
		}

		else if (data->in) // >>
		{
			redirect_fd = open("file.txt", O_CREAT | O_APPEND);
			dup2(redirect_fd, STDOUT_FILENO);
			close(redirect_fd);
		}
	}
}

int	main(int argc, char **argv, char **envp)
{
	char	*cmd[] = {"ls" "-l", 0};
	char	*file = cmd[0];

	if (execve("/usr/bin/ls", cmd, envp) ==  -1)
		printf("Error executing %s\n", file);

	printf("Done\n");
}
