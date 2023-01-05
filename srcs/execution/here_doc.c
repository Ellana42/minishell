#include "execution.h"

void	eof_err(char *delimiter)
{
	ft_putstr_fd("warning: here-document delimited by end-of-file", 2);
	ft_putstr_fd(" (wanted `", 2);
	ft_putstr_fd(delimiter, 2);
	ft_putstr_fd("')\n", 2);
}

int	get_here_doc(char *delimiter, int fd[2], int len_delimiter)
{
	char	*line;
	char	*expanded_line;
	int		end;

	line = readline("> ");
	expanded_line = expand(line, glob_get_exit_status());
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

int	get_heredoc_loop(char *delimiter, int fd[2])
{
	char	eof;
	int		len_delimiter;
	int		end;

	end = 0;
	eof = 0;
	len_delimiter = ft_strlen(delimiter);
	while (!end)
		end = get_here_doc(delimiter, fd, len_delimiter);
	write(fd[1], &eof, 1);
	return (0);
}

int	execution_get_heredoc(t_execution *execution, char *delimiter, \
		t_executable *executable, int index)
{
	int	pid;
	int	status;

	if (pipe((executable->in_files)[index]) == -1)
		(executable->in_files)[index][0] = -1;
	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		status = get_heredoc_loop(delimiter, (executable->in_files)[index]);
		close((executable->in_files)[index][0]);
		close((executable->in_files)[index][1]);
		clean_table_in(executable->in_files, executable->command);
		free(executable->in_files);
		free(executable);
		minishell_destroy(execution->minishell);
		parser_destroy(execution->parser);
		execution_destroy(execution);
		glob_destroy();
		exit(status);
	}
	else
	{
		pid = waitpid(-1, &status, 0);
		if (pid == glob_get_last_pid())
			status = WEXITSTATUS(status);
	}
	return (status);
}
