#include "execution.h"

// TODO redo heredoc with tables
int	get_here_doc(char *delimiter)
{
	int		tmp_fd;
	int		len_delimiter;
	char	*line;
	int		flag;

	if (!delimiter)
		return (-2);

	len_delimiter = ft_strlen(delimiter);
	tmp_fd = open(".heredoc.tmp", O_TRUNC | O_CREAT | O_WRONLY , 0644); // TODO protect open

	if (tmp_fd < 0)
		return (tmp_fd);

	line = "";

	flag = 1;

	while (flag)
	{
		line = readline("> "); // TODO deal with leaks (rl_clear_history)

		if (line == NULL)
			break ;
		
		if (!ft_strncmp(line, delimiter, len_delimiter + 1))
			flag = 0;

		else
		{
			ft_putstr_fd(line, tmp_fd); // sinon on stocke la ligne dans le fichier tempo
			ft_putstr_fd("\n", tmp_fd);
		}
		free(line);
	}
	close(tmp_fd);
	tmp_fd = open(".heredoc.tmp", O_RDONLY , 0644); // TODO protect open
	return (tmp_fd);
}
