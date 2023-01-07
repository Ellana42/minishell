/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:51:56 by mkaploun          #+#    #+#             */
/*   Updated: 2023/01/07 11:52:00 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_struct.h"

extern t_glob	*g_glob;

void	minishell_signal_ctrl_c(int signum)
{
	(void)signum;
	printf("^C\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	glob_set_exit_status(130);
}

void	exec_signal_ctrl_slash(int signum)
{
	(void)signum;
	write(1, "Quit (core dumped)\n", 19);
	glob_set_exit_status(131);
}

void	exec_signal_ctrl_c(int signum)
{
	(void)signum;
}

void	heredoc_signal_ctrl_c(int signum)
{
	(void)signum;
	close(glob_get_exit_status());
	glob_destroy();
	printf("^C\n");
	exit(130);
}
