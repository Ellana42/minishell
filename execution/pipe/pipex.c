/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 12:19:30 by lsalin            #+#    #+#             */
/*   Updated: 2022/11/30 15:14:18 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_child(char **argv, char **envp, int pipefd[2], int fd[2])
{
	char	**cmd_and_options;
	char	*path_ultime;
	int		pid1;

	cmd_and_options = ft_split(argv[2], ' ');
	path_ultime = find_path(cmd_and_options[0], envp);
	pid1 = fork();
	if (pid1 == -1)
		error();
	if (pid1 == 0)
	{
		dup2(pipefd[1], STDOUT_FILENO);
		dup2(fd[0], STDIN_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);
		close(fd[0]);
		close(fd[1]);
		execve(path_ultime, cmd_and_options, envp);
	}
	free_strs(path_ultime, cmd_and_options);
}

void	second_child(char **argv, char **envp, int pipefd[2], int fd[2])
{
	char	**cmd_and_options;
	char	*path_ultime;
	int		pid2;

	cmd_and_options = ft_split(argv[3], ' ');
	path_ultime = find_path(cmd_and_options[0], envp);
	pid2 = fork();
	if (pid2 == -1)
		error();
	if (pid2 == 0)
	{
		dup2(pipefd[0], STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(pipefd[1]);
		close(pipefd[0]);
		close(fd[1]);
		close(fd[0]);
		execve(path_ultime, cmd_and_options, envp);
	}
	free_strs(path_ultime, cmd_and_options);
}

int	main(int argc, char *argv[], char **envp)
{
	int		pipefd[2];
	int		fd[2];

	if (argc == 5)
	{
		if (envp[0] == NULL)
			error();
		fd[0] = open(argv[1], O_RDONLY);
		if (fd[0] == -1)
			error();
		fd[1] = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
		if (fd[1] == -1)
			error();
		if (pipe(pipefd) == -1)
			error();
		first_child(argv, envp, pipefd, fd);
		second_child(argv, envp, pipefd, fd);
		close_fd(pipefd, fd);
		waitpid(-1, NULL, 0);
		waitpid(-1, NULL, 0);
	}
	else
		ft_print_putstr();
	return (0);
}
