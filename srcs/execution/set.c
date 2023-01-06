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

void	execution_set_terminal(t_execution *execution, int terminal_index)
{
	t_minishell	*minishell;

	minishell = execution_get_minishell(execution);
	minishell_set_terminal(minishell, terminal_index);
}
