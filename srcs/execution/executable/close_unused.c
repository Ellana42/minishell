#include "executable.h"

int	executable_close_unused_infiles(t_executable *executable)
{
	return (_close_in_fd_table(executable->in_files, executable->in_size - 1));
}

int	executable_close_unused_outfiles(t_executable *executable)
{
	return (_close_fd_table(executable->out_files, executable->out_size - 1));
}
