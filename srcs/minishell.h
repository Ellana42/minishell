#ifndef MINISHELL_H
# define MINISHELL_H

# include "parsing/parsing.h"
# include "execution/execution.h"
# include <stdio.h>
# include <termios.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "glob.h"
# include "../libft/includes/libft.h"

typedef struct sigaction	t_sa;

int			init_sa(t_sa *sa_c);

#endif
