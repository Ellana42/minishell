#include "minishell.h"

extern int t_glob;

static void	handler(int sig, siginfo_t *si, void *ucontext)
{
	(void) si;
	(void) ucontext;
	(void) sig;
	if (sig == SIGINT)
	{
		// TODO stop all running programs and exit
		t_glob = 0;
	}
	if (sig == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
	}
}

int	init_sa(sa *sa_c)
{
	sigemptyset(&sa_c->sa_mask);
	sa_c->sa_flags = SA_SIGINFO;
	sa_c->sa_sigaction = handler;
	sigaction(SIGINT, sa_c, NULL);
	sigaction(SIGQUIT, sa_c, NULL);
	sigaction(SIGTSTP, sa_c, NULL);
	return (0);
}
