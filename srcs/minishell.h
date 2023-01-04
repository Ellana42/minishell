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
# include "glob/glob.h"
# include "../libft/includes/libft.h"

# define BASE_TERMINAL 0
# define MINISHELL_TERMINAL 1
# define HEREDOC_TERMINAL 2

typedef struct s_minishell {
	struct termios	terminal[3];
	t_list			***env;
}	t_minishell;

typedef struct sigaction	t_sa;

/* int			init_sa(t_sa *sa_c); */
void		signal_reset_prompt(int signo);
void		set_signals_interactive(void);
void		signal_print_newline(int signal);
void		set_signals_noninteractive(void);
void		signal_ctrl_c(int signum);
void		signal_ctrl_slash(int signum);
void		minishell_destroy(t_minishell *minishell);
t_minishell	*minishell_alloc(void);
int			minishell_init(t_minishell *minishell, char **envp);
t_list	**minishell_get_env(t_minishell *minishell);
struct termios	*minishell_get_terminal(t_minishell *minishell, int term_index);
void	minishell_set_terminal(t_minishell *minishell, int terminal_index);
void	minishell_terminals_init(t_minishell *minishell);

#endif
