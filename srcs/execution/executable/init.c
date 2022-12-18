#include "executable.h"

t_executable	*executable_alloc(void)
{
	t_executable	*executable;

	executable = (t_executable *)malloc(sizeof(t_executable));
	return (executable);
}

int	executable_init(t_executable *executable, t_command *command, int **pipes, int index)
{
	int		*in_table;
	int		*out_table;
	char	*filename;

	if (!executable)
		return (1);
	executable->command = command;
	if (index == 0)
	    executable->in_pipe = NULL;
	else
	    executable->in_pipe = pipes[index - 1];
	if (index == pipes_get_size(pipes))
		executable->out_pipe = NULL;
	else
		executable->out_pipe = pipes[index];
	executable->in_files = in_table;
	if (get_in_table(command, &(executable->in_files), &filename, &executable->in_size))
		return (1);
	if (!executable->in_files)
		return (1);
	executable->out_files = out_table;
	if (get_out_table(command, &(executable->out_files), &executable->out_size))
		return (1);
	if (!executable->out_files)
		return (1);
	return (0);
}
