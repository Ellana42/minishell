#include "minishell.h"

extern t_glob *g_glob;

int	interrupt_execution()
{
	int	pid;

	while (!glob_pop_pid(&pid))
	{
		printf("Killing %d\n", pid);
		kill(pid, SIGINT);
		printf("Killed %d\n", pid);
	}
	return (0);
}

static void	handler(int sig, siginfo_t *si, void *ucontext)
{
	(void) si;
	(void) ucontext;
	(void) sig;
	if (sig == SIGINT)
	{
		// TODO stop all running programs and exit
		/* g_glob->activated = 0; */
		interrupt_execution();
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
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
