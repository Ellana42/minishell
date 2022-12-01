/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 12:19:30 by lsalin            #+#    #+#             */
/*   Updated: 2022/12/01 20:46:32 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	first_child(t_data *data)
{
	char	**cmd_and_options;
	char	*path_ultime;
	int		pid1;

	cmd_and_options = ft_split(data->argv[2], ' ');
	path_ultime = find_path(data);
	pid1 = fork();
	if (pid1 == -1)
		error();
	if (pid1 == 0)
	{
		dup2(data->pipefd[1], STDOUT_FILENO);
		dup2(data->fd[0], STDIN_FILENO);
		close(data->pipefd[0]);
		close(data->pipefd[1]);
		close(data->fd[0]);
		close(data->fd[1]);
		execve(path_ultime, cmd_and_options, data->envp);
	}
	free_strs(path_ultime, cmd_and_options, NULL);
}

void	second_child(t_data *data)
{
	char	**cmd_and_options;
	char	*path_ultime;
	int		pid2;

	cmd_and_options = ft_split(data->argv[3], ' ');
	path_ultime = find_path(data);
	pid2 = fork();
	if (pid2 == -1)
		error();
	if (pid2 == 0)
	{
		dup2(data->pipefd[0], STDIN_FILENO);
		dup2(data->fd[1], STDOUT_FILENO);
		close(data->pipefd[1]);
		close(data->pipefd[0]);
		close(data->fd[1]);
		close(data->fd[0]);
		execve(path_ultime, cmd_and_options, data->envp);
	}
	free_strs(path_ultime, cmd_and_options, NULL);
}

int	main(int argc, char *argv[], char **envp)
{
	t_data	*data;
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
		first_child(data);
		second_child(data);
		close_fd(data);
		waitpid(-1, NULL, 0);
		waitpid(-1, NULL, 0);
	}
	else
		ft_print_putstr();
	return (0);
}
