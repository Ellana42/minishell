#include "executable.h"

void	executable_dispose(t_executable *executable)
{
	free(executable->in_files); // TODO double check
	free(executable->out_files);
}

void	executable_free(t_executable *executable)
{}

void	executable_destroy(t_executable *executable)
{
	executable_dispose(executable);
	executable_free(executable);
}
