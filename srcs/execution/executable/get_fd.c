#include "executable.h"

int	executable_get_in_close(t_executable *executable, int *fd)
{
	if (executable->in_size == 0 && !executable->in_pipe)
	{
		*fd = STDIN_FILENO;
		return (0);
	}
	if (executable->in_size == 0)
	{
		*fd = executable->in_pipe[1];
		return (executable_close_infiles(executable));
	}
	if (close_pipe(executable->in_pipe))	
		return (1);
	*fd = executable->in_files[executable->in_size - 1];
	return (executable_close_unused_infiles(executable));
}

int	executable_get_out_close(t_executable *executable, int *fd)
{
	if (executable->out_size == 0 && !executable->out_pipe)
	{
		*fd = STDOUT_FILENO;
		return (0);
	}
	if (executable->out_size == 0)
	{
		*fd = executable->out_pipe[1];
		return (executable_close_outfiles(executable));
	}
	if (close_pipe(executable->out_pipe))	
		return (1);
	*fd = executable->out_files[executable->out_size - 1];
	return (executable_close_unused_outfiles(executable));
}

// fd[0] is the input, fd[1] the output
int	executable_get_fds_close(t_executable *executable, int fd[2])
{
	if (executable_get_in_close(executable, &fd[0]))
		return (1);
	return (executable_get_out_close(executable, &fd[1]));
}
