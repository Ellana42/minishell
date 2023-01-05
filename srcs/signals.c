#include "minishell.h"

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
}

void	exec_signal_ctrl_c(int signum)
{
	(void)signum;
	glob_set_exit_status(-5);
}

void	heredoc_signal_ctrl_c(int signum)
{
	(void)signum;
	printf("\n");
	exit(0);
}
