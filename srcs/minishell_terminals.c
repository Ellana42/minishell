#include "minishell.h"

void	minishell_heredoc_terminal_init(t_minishell *minishell)
{
	struct termios	*heredoc_terminal;

	heredoc_terminal = minishell_get_terminal(minishell, HEREDOC_TERMINAL);
	heredoc_terminal->c_lflag &= ~ECHOCTL;
	heredoc_terminal->c_cc[VINTR] = NO_KEY;
	heredoc_terminal->c_cc[VQUIT] = CTRL_C;
}

void	minishell_minishell_terminal_init(t_minishell *minishell)
{
	struct termios	*minishell_terminal;

	minishell_terminal = minishell_get_terminal(minishell, MINISHELL_TERMINAL);
	minishell_terminal->c_lflag &= ~ECHOCTL;
	minishell_terminal->c_cc[VQUIT] = NO_KEY;
}

void	minishell_terminals_init(t_minishell *minishell)
{
	struct termios	*base_terminal;
	struct termios	*minishell_terminal;
	struct termios	*heredoc_terminal;

	rl_catch_signals = 0;
	base_terminal = &minishell->terminal[BASE_TERMINAL];
	minishell_terminal = &minishell->terminal[MINISHELL_TERMINAL];
	heredoc_terminal = &minishell->terminal[HEREDOC_TERMINAL];
	tcgetattr(STDIN_FILENO, base_terminal);
	ft_memcpy(minishell_terminal, base_terminal, sizeof(struct termios));
	ft_memcpy(heredoc_terminal, base_terminal, sizeof(struct termios));
	minishell_minishell_terminal_init(minishell);
	minishell_heredoc_terminal_init(minishell);
}
