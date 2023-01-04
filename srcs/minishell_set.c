#include "minishell.h"

void	minishell_set_terminal(t_minishell *minishell, int terminal_index)
{
	struct termios	*new_terminal;

	new_terminal = minishell_get_terminal(minishell, terminal_index);
	if (terminal_index == MINISHELL_TERMINAL)
	{
		signal(SIGINT, &signal_ctrl_c);
		signal(SIGQUIT, &signal_ctrl_slash);
	}
	tcsetattr(STDIN_FILENO, TCSANOW, new_terminal);
}
