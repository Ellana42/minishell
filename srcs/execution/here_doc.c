#include "execution.h"

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
		end = 1;
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

int	execution_get_heredoc(char *delimiter, int fd[2])
{
	char	eof;
	int		len_delimiter;
	int		end;

	end = 0;
	eof = 0;
	len_delimiter = ft_strlen(delimiter);
	if (pipe(fd) == -1)
		fd[0] = -1;
	while (!end)
		end = get_here_doc(delimiter, fd, len_delimiter);
	write(fd[1], &eof, 1);
	return (0);
}
