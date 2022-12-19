#include "execution.h"

// TODO check for security
// TODO check heredocs closed properly

int	execution_get_heredoc(char *delimiter, int fd[2])
{
	int		end;
	char	*line;
	int		len_delimiter;
	char	eof;

	end = 0;
	eof = 0;
	len_delimiter = ft_strlen(delimiter);
	if (pipe(fd) == -1)
		fd[0] = -1;
	while (!end)
	{
		line = readline("> "); // TODO deal with leaks (rl_clear_history)
		if (line == NULL)
			end = 1;
		else if (!ft_strncmp(line, delimiter, len_delimiter + 1))
			end = 1;
		else
		{
			ft_putstr_fd(line, fd[1]); // sinon on stocke la ligne dans le fichier tempo
			ft_putstr_fd("\n", fd[1]);
		}
		free(line);
	}
	write(fd[1], &eof, 1);
	return (0);
}
