#include "executable.h"

t_executable	*executable_alloc(void)
{
	t_executable	*executable;

	executable = (t_executable *)malloc(sizeof(t_executable));
	return (executable);
}

int	extecutable_file_init(t_execution *exec, t_executable *exe)
{
	char	*filename;

	if (get_in_table(exe, exec, &filename))
		return (1);
	if (!exe->in_files)
		return (1);
	if (get_out_table(exe->command, &(exe->out_files), &exe->out_size))
		return (1);
	if (!exe->out_files)
		return (1);
	return (0);
}

int	executable_init(t_execution *execution, t_executable *exe, t_command *cmd, \
		int index)
{
	if (!exe)
		return (1);
	exe->command = cmd;
	if (index == 0)
		exe->in_pipe = NULL;
	else
		exe->in_pipe = execution->pipes[index - 1];
	if (index == pipes_get_size(execution->pipes))
		exe->out_pipe = NULL;
	else
		exe->out_pipe = execution->pipes[index];
	if (extecutable_file_init(execution, exe))
		return (1);
	return (0);
}
