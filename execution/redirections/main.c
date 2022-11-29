/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:13:54 by lsalin            #+#    #+#             */
/*   Updated: 2022/11/29 16:43:01 by lsalin           ###   ########.fr       */
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

int	main(int argc, char **argv, char **envp)
{
	char	*cmd[] = {"ls" "-l", 0};
	char	*file = cmd[0];

	if (execve("/usr/bin/ls", cmd, envp) ==  -1)
		printf("Error executing %s\n", file);

	printf("Done\n");
}

int	redirecting_stdin(t_command *data)
{
	int	pid;
	int	file;
	int	file_in;
	pid = fork();

	if (pid == -1)
		return (1);

	if (pid == 0)
	{
		file = open("file.txt", O_CREAT | O_WRONLY, 0777);

		if (file == 1)
			return (2);

		file_in = dup2(file, STDIN_FILENO);

		close(file);
	}
}

int	redirecting_stdout(t_command *data)
{
	int	pid;
	int	file;
	int	file_out;
	pid = fork();

	if (pid == -1)
		return (1);

	if (pid == 0) // processus fils
	{
		file = open("file.txt", O_CREAT | O_WRONLY, 0777); // file = int du fd

		if (file == 1)
			return (2);

		file_out = dup2(file, STDOUT_FILENO); // file_out = prends la place de la stdout
											// si on printf() ca s'affichera dans notre file_out !

		close(file);
	}
}
