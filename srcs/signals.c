#include "minishell.h"

extern t_glob	*g_glob;

void	sig_exit(int signum)
{
	(void)signum;
	if (rl_line_buffer[0])
		return ;
	rl_clear_history();
	glob_set_state(0);
}

void	sig_nl(int signum)
{
	(void)signum;
	/* write(1, "^C\n", 3); */
	printf("$> ^C\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	glob_set_exit_status(130);
}
