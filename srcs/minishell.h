#ifndef MINISHELL_H
# define MINISHELL_H

# include "parsing/parsing.h"
# include "execution/execution.h"
# include <stdio.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/includes/libft.h"

typedef struct sigaction	sa;
static void	handler(int sig, siginfo_t *si, void *ucontext);
int	init_sa(sa *sa_c);

#endif
