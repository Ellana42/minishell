#include "minishell.h"

extern t_glob	*g_glob;

// TODO check error
static void	handler(int sig, siginfo_t *si, void *ucontext)
{
	(void) si;
	(void) ucontext;
	(void) sig;
	if (glob_is_running())
	{
		rl_on_new_line();
		glob_set_exit_status(-5);
	}
	else
	{
		if (sig == SIGINT)
		{
			printf("\n");
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();
			glob_set_exit_status(130);
		}
	}
}

int	init_sa(t_sa *sa_c)
{
	struct sigaction	sa_ign;

	ft_memset(&sa_ign, 0, sizeof(sa_ign));
	sa_ign.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &sa_ign, NULL);
	sigemptyset(&sa_c->sa_mask);
	sa_c->sa_flags = SA_SIGINFO;
	sa_c->sa_sigaction = handler;
	sigaction(SIGINT, sa_c, NULL);
	sigaction(SIGQUIT, sa_c, NULL);
	sigaction(SIGTSTP, sa_c, NULL);
	return (0);
}
