#include "executable.h"

int	_close_fd_table(int *table, size_t table_size)
{
	int	i;

	i = 0;
	while (i < table_size)
	{
		if (close_fd(table[i]))
			return (1);
		i++;
	}
	return (0);
}

int executable_close_infiles(t_executable *executable)
{
	return (_close_fd_table(executable->in_files, executable->in_size));
}

int executable_close_outfiles(t_executable *executable)
{
	return (_close_fd_table(executable->out_files, executable->out_size));
}

int executable_close_unused_infiles(t_executable *executable)
{
	return (_close_fd_table(executable->in_files, executable->in_size - 1));
}

int executable_close_unused_outfiles(t_executable *executable)
{
	return (_close_fd_table(executable->out_files, executable->out_size - 1));
}

int	executable_close_files(t_executable *executable)
{
	if (executable_close_infiles(executable))
		return (1);
	if (executable_close_outfiles(executable))
		return (1);
	return (0);
}