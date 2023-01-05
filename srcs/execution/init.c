#include "execution.h"

extern t_glob	*g_glob;

t_execution	*execution_alloc(void)
{
	t_execution	*execution;

	execution = (t_execution *)malloc(sizeof(t_execution));
	if (!execution)
		return (execution);
	execution->pipes = NULL;
	execution->executables = NULL;
	execution->pids = NULL;
	execution->current_executable = NULL;
	execution->parser = NULL;
	return (execution);
}

int	execution_init(t_execution *execution, t_parser *parser, t_minishell *m)
{
	size_t			commands_size;
	t_executable	*executable;
	t_commands		*cmds;

	if (!execution)
		return (1);
	commands_size = commands_get_size(parser->commands);
	execution->executables_size = commands_size;
	execution->executable_index = 0;
	execution->parser = parser;
	cmds = parser->commands;
	execution->minishell = m;
	if (init_pipes(&execution->pipes, commands_size))
		return (1);
	execution->executables = executables_alloc();
	if (executables_init(execution->executables, cmds, execution->pipes))
		return (1);
	executable = executables_get_i(execution->executables, 0);
	execution->current_executable = executable;
	execution->pids = intlstinit();
	if (!execution->pids)
		return (1);
	return (0);
}
