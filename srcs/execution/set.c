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

void	execution_set_terminal(t_execution *execution, int terminal_index)
{
	t_minishell	*minishell;

	minishell = execution_get_minishell(execution);
	minishell_set_terminal(minishell, terminal_index);
}
