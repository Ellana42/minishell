#include "minishell.h"

extern t_glob	*g_glob;

int	interrupt_execution(void)
{
	int	pid;

	while (!glob_pop_pid(&pid))
	{
		if (kill(pid, SIGINT) == -1)
			return (1);
	}
	return (0);
}

// TODO check error
static void	handler(int sig, siginfo_t *si, void *ucontext)
{
	(void) si;
	(void) ucontext;
	(void) sig;
	if (sig == SIGINT)
	{
		if (glob_is_running())
		{
			interrupt_execution();
			glob_set_exit_status(-5);
		}
		else
		{
			printf("\n");
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();
			glob_set_exit_status(130);
		}
	}
	if (sig == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
	}
}

int	init_sa(t_sa *sa_c)
{
	sigemptyset(&sa_c->sa_mask);
	sa_c->sa_flags = SA_SIGINFO;
	sa_c->sa_sigaction = handler;
	sigaction(SIGINT, sa_c, NULL);
	sigaction(SIGQUIT, sa_c, NULL);
	sigaction(SIGTSTP, sa_c, NULL);
	return (0);
}
