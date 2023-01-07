/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:52:38 by mkaploun          #+#    #+#             */
/*   Updated: 2023/01/07 11:52:44 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	get_heredoc_loop(char *delimiter, int fd[2], int last_exit_status)
{
	char	eof;
	int		len_delimiter;
	int		end;

	end = 0;
	eof = 0;
	len_delimiter = ft_strlen(delimiter);
	while (!end)
		end = get_here_doc(delimiter, fd, len_delimiter, last_exit_status);
	write(fd[1], &eof, 1);
	return (0);
}

void	launch_heredoc(t_execution *execution, \
		char delimiter_str[MAX_DELIMITER], t_executable *executable, int index)
{
	int		fd[2];
	int		status;
	int		last_exit_status;

	last_exit_status = glob_get_exit_status();
	fd[0] = (executable->in_files)[index][0];
	fd[1] = (executable->in_files)[index][1];
	glob_set_exit_status(fd[1]);
	close(fd[0]);
	close_pipes(execution);
	close_precedent_infiles(executable, index);
	close_everything(execution, executable->index);
	executable_destroy(executable);
	minishell_destroy(execution->minishell);
	parser_destroy(execution->parser);
	execution_destroy(execution);
	status = get_heredoc_loop(delimiter_str, fd, last_exit_status);
	close(glob_get_exit_status());
	glob_destroy();
	exit(status);
}

int	heredoc_main(t_execution *execution, \
		t_executable *executable, int index)
{
	int	status;

	execution_set_terminal(execution, HEREDOC_WAIT_TERMINAL);
	waitpid(-1, &status, 0);
	if (WIFSIGNALED(status))
		status = 128 + WTERMSIG(status);
	else if (WIFEXITED(status))
		status = WEXITSTATUS(status);
	execution_set_terminal(execution, BASE_TERMINAL);
	if (status == 130)
	{
		if (executable->index == execution->executables_size - 1)
			glob_set_exit_status(-5);
		close((executable->in_files)[index][0]);
		close((executable->in_files)[index][1]);
		(executable->in_files)[index][0] = -1;
		(executable->in_files)[index][1] = -1;
	}
	return (status);
}

int	execution_get_heredoc(t_execution *execution, char *delimiter, \
		t_executable *executable, int index)
{
	int		pid;
	int		status;
	int		last_exit_status;
	char	delimiter_str[MAX_DELIMITER];

	status = 0;
	last_exit_status = glob_get_exit_status();
	if (ft_strlen(delimiter) + 1 > MAX_DELIMITER)
		return (error_msg3("Delimiter string too long", 1));
	ft_strlcpy(delimiter_str, delimiter, ft_strlen(delimiter) + 1);
	if (pipe((executable->in_files)[index]) == -1)
		(executable->in_files)[index][0] = -1;
	execution_set_terminal(execution, HEREDOC_TERMINAL);
	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
		launch_heredoc(execution, delimiter_str, executable, index);
	status = heredoc_main(execution, executable, index);
	if (status != 130)
		glob_set_exit_status(last_exit_status);
	return (status);
}
