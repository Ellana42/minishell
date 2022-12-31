#include "executable.h"

t_executable	*executable_alloc(void)
{
	t_executable	*executable;

	executable = (t_executable *)malloc(sizeof(t_executable));
	return (executable);
}

int	extecutable_file_init(t_executable *exe, t_command *cmd)
{
	char	*filename;

	if (get_in_table(cmd, &(exe->in_files), &filename, &exe->in_size))
		return (1);
	if (!exe->in_files)
		return (1);
	if (get_out_table(cmd, &(exe->out_files), &exe->out_size))
		return (1);
	if (!exe->out_files)
		return (1);
	return (0);
}

int	executable_init(t_executable *exe, t_command *cmd, int **pipes, int index)
{
	if (!exe)
		return (1);
	exe->command = cmd;
	if (index == 0)
		exe->in_pipe = NULL;
	else
		exe->in_pipe = pipes[index - 1];
	if (index == pipes_get_size(pipes))
		exe->out_pipe = NULL;
	else
		exe->out_pipe = pipes[index];
	if (extecutable_file_init(exe, cmd))
		return (1);
	return (0);
}
