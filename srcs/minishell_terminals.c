/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_terminals.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:51:56 by mkaploun          #+#    #+#             */
/*   Updated: 2023/01/07 11:52:00 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_struct.h"

void	minishell_heredoc_terminal_init(t_minishell *minishell)
{
	struct termios	*heredoc_terminal;

	heredoc_terminal = minishell_get_terminal(minishell, HEREDOC_TERMINAL);
	heredoc_terminal->c_lflag &= ~ECHOCTL;
	heredoc_terminal->c_cc[VQUIT] = NO_KEY;
	heredoc_terminal->c_cc[VINTR] = CTRL_C;
}

void	minishell_minishell_terminal_init(t_minishell *minishell)
{
	struct termios	*minishell_terminal;

	minishell_terminal = minishell_get_terminal(minishell, MINISHELL_TERMINAL);
	minishell_terminal->c_lflag &= ~ECHOCTL;
	minishell_terminal->c_cc[VQUIT] = NO_KEY;
	minishell_terminal->c_cc[VINTR] = CTRL_C;
}

void	minishell_heredoc_wait_terminal_init(t_minishell *minishell)
{
	struct termios	*terminal;

	terminal = minishell_get_terminal(minishell, HEREDOC_WAIT_TERMINAL);
	terminal->c_lflag &= ~ECHOCTL;
	terminal->c_cc[VQUIT] = NO_KEY;
}

int	minishell_terminals_init(t_minishell *minishell)
{
	struct termios	*base_terminal;
	struct termios	*minishell_terminal;
	struct termios	*heredoc_terminal;
	struct termios	*heredoc_wait_terminal;

	rl_catch_signals = 0;
	if (!isatty(STDIN_FILENO))
	{
		minishell_destroy(minishell);
		return (error_msg3("Input is not a tty", 1));
	}
	base_terminal = &minishell->terminal[BASE_TERMINAL];
	minishell_terminal = &minishell->terminal[MINISHELL_TERMINAL];
	heredoc_terminal = &minishell->terminal[HEREDOC_TERMINAL];
	heredoc_wait_terminal = &minishell->terminal[HEREDOC_WAIT_TERMINAL];
	tcgetattr(STDIN_FILENO, base_terminal);
	ft_memcpy(minishell_terminal, base_terminal, sizeof(struct termios));
	ft_memcpy(heredoc_terminal, base_terminal, sizeof(struct termios));
	ft_memcpy(heredoc_wait_terminal, base_terminal, sizeof(struct termios));
	minishell_minishell_terminal_init(minishell);
	minishell_heredoc_terminal_init(minishell);
	minishell_heredoc_wait_terminal_init(minishell);
	return (0);
}
