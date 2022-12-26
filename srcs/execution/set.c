#include "execution.h"

void	execution_move(t_execution *execution)
{
	t_executable	*executable;
	int				index;

	execution->executable_index++;
	index = execution->executable_index;
	executable = execution_get_executable_i(execution, index);
	execution->current_executable = executable;
}

int	execution_store_pid(t_execution *execution, int pid)
{
	t_intlist	*new_lst;

	new_lst = intlstnew(pid);
	if (!new_lst)
		return (1);
	intlstadd_back(execution->pids, new_lst);
	return (0);
}

int	execution_pop_pid(t_execution *execution, int *pid)
{
	return (intlst_pop(execution->pids, pid));
}
