#include "execution.h"

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
	char	delimiter_str[4096];

	last_exit_status = glob_get_exit_status();
	if (ft_strlen(delimiter) + 1 > 4096)
	{
		printf("Delimiter string too long\n");
		return (1);
	}
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
		clean_table_in(executable->in_files, executable->command);
		free(executable->in_files);
		free(executable);
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
		if (pid == glob_get_last_pid())
			status = WEXITSTATUS(status);
		execution_set_terminal(execution, BASE_TERMINAL);
		glob_set_exit_status(last_exit_status);
	}
	return (status);
}
