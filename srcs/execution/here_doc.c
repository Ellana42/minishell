#include "execution.h"

void	close_precedent_infiles(t_executable *executable, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		close_fd((executable->in_files)[i][0]);
		close_fd((executable->in_files)[i][1]);
		i++;
	}
}

// TODO close every fd for executables before current executable
int	close_everything(t_execution *execution, int index)
{
	int				i;
	t_executable	*executable;

	i = 0;
	while (i < execution->executables_size)
	{
		if (i < index)
		{
			executable = execution_get_executable_i(execution, i);
			if (executable_close_files(executable))
				return (1);
		}
		i++;
	}
	return (0);
}

void	eof_err(char *delimiter)
{
	ft_putstr_fd("warning: here-document delimited by end-of-file", 2);
	ft_putstr_fd(" (wanted `", 2);
	ft_putstr_fd(delimiter, 2);
	ft_putstr_fd("')\n", 2);
}

int	get_here_doc(char *delimiter, int fd[2], int len_delimiter, int exit)
{
	char	*line;
	char	*expanded_line;
	int		end;

	line = readline("> ");
	expanded_line = expand(line, exit);
	free(line);
	end = 0;
	if (!expanded_line)
	{
		eof_err(delimiter);
		end = 1;
	}
	else if (!ft_strncmp(expanded_line, delimiter, len_delimiter + 1))
		end = 1;
	else
	{
		ft_putstr_fd(expanded_line, fd[1]);
		ft_putstr_fd("\n", fd[1]);
	}
	free(expanded_line);
	return (end);
}

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

int	execution_get_heredoc(t_execution *execution, char *delimiter, \
		t_executable *executable, int index)
{
	int		pid;
	int		status;
	int		fd[2];
	int		last_exit_status;
	char	delimiter_str[MAX_DELIMITER];
	int		i;

	i = 0;
	last_exit_status = glob_get_exit_status();
	if (ft_strlen(delimiter) + 1 > MAX_DELIMITER)
		return (error_msg3("Delimiter string too long", 1));
	ft_strlcpy(delimiter_str, delimiter, ft_strlen(delimiter) + 1);
	if (pipe((executable->in_files)[index]) == -1)
		(executable->in_files)[index][0] = -1;
	fd[0] = (executable->in_files)[index][0];
	fd[1] = (executable->in_files)[index][1];
	execution_set_terminal(execution, HEREDOC_TERMINAL);
	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		glob_set_exit_status(fd[1]);
		close(fd[0]);
		while (i < pipes_get_size(execution->pipes))
		{
			close_pipe(execution->pipes[i]);
			i++;
		}
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
	else
	{
		execution_set_terminal(execution, HEREDOC_WAIT_TERMINAL);
		pid = waitpid(-1, &status, 0);
		status = WEXITSTATUS(status);
		execution_set_terminal(execution, BASE_TERMINAL);
		if (status == 130)
		{
			glob_set_exit_status(-5);
			close(fd[0]);
			close(fd[1]);
			(executable->in_files)[index][0] = -1;
			(executable->in_files)[index][1] = -1;
		}
		else
			glob_set_exit_status(last_exit_status);
	}
	return (status);
}
