/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:51:56 by mkaploun          #+#    #+#             */
/*   Updated: 2023/01/07 11:52:00 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	minishell_set_terminal(t_minishell *minishell, int terminal_index)
{
	struct termios	*new_terminal;

	new_terminal = minishell_get_terminal(minishell, terminal_index);
	if (terminal_index == MINISHELL_TERMINAL)
	{
		signal(SIGINT, &minishell_signal_ctrl_c);
	}
	if (terminal_index == BASE_TERMINAL)
	{
		signal(SIGINT, &exec_signal_ctrl_c);
		signal(SIGQUIT, &exec_signal_ctrl_slash);
	}
	if (terminal_index == HEREDOC_TERMINAL)
	{
		signal(SIGINT, &heredoc_signal_ctrl_c);
	}
	if (terminal_index == HEREDOC_WAIT_TERMINAL)
	{
		signal(SIGINT, &exec_signal_ctrl_c);
		signal(SIGQUIT, &exec_signal_ctrl_slash);
	}
	tcsetattr(STDIN_FILENO, TCSANOW, new_terminal);
}
