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
	get_in_table(command, &in_table, &filename, &executable->in_size);
	if (!in_table)
		return (1);
	executable->out_files = out_table;
	get_out_table(command, &out_table, &executable->out_size);
	if (!out_table)
		return (1);
	return (0);
}
