#ifndef MINISHELL_H
# define MINISHELL_H

# include "error.h"
# include "parsing/parsing.h"
# include "execution/execution.h"
# include <stdio.h>
# include <termios.h>
# include <term.h>
# include <curses.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "glob.h"
# include "../libft/includes/libft.h"

typedef struct sigaction	t_sa;

/* int			init_sa(t_sa *sa_c); */
void		signal_reset_prompt(int signo);
void		set_signals_interactive(void);
void		signal_print_newline(int signal);
void		set_signals_noninteractive(void);
void		signal_ctrl_c(int signum);
void		signal_ctrl_slash(int signum);

#endif
