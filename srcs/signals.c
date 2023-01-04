#include "minishell.h"

extern t_glob	*g_glob;

void	signal_ctrl_slash(int signum)
{
	(void)signum;
	if (glob_is_running())
	{
		printf("^\\Quit :3\n");
		if (rl_line_buffer[0])
			return ;
		rl_clear_history();
	}
}

void	signal_ctrl_c(int signum)
{
	(void)signum;
	if (glob_is_running())
	{
		printf("^C\n");
		rl_on_new_line();
		glob_set_exit_status(-5);
	}
	else
	{
		printf("^C\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		glob_set_exit_status(130);
	}
}
