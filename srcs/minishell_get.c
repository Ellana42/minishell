#include "minishell.h"

t_list	**minishell_get_env(t_minishell *minishell)
{
	return (*(minishell->env));
}

struct termios	*minishell_get_terminal(t_minishell *minishell, int term_index)
{
	if (term_index > 3)
		return (NULL);
	return (&minishell->terminal[term_index]);
}
