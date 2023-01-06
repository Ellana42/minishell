#include "minishell.h"

t_minishell	*minishell_alloc(void)
{
	t_minishell	*minishell;

	minishell = (t_minishell *)malloc(sizeof(t_minishell));
	if (!minishell)
		return (minishell);
	minishell->env = NULL;
	return (minishell);
}

int	minishell_init(t_minishell *minishell, char **envp)
{
	if (!minishell)
		return (1);
	minishell->env = (t_list ***)malloc(sizeof(t_list **));
	if (!minishell->env)
		return (1);
	if (realloc_env_vars(envp, minishell->env))
		return (1);
	if (!*minishell->env)
		return (1);
	if (minishell_terminals_init(minishell))
		return (1);
	return (0);
}

void	minishell_dispose(t_minishell *minishell)
{
	ft_lstclear(*minishell->env, &env_el_destroy);
	free(*minishell->env);
	free(minishell->env);
}

void	minishell_free(t_minishell *minishell)
{
	free(minishell);
}

void	minishell_destroy(t_minishell *minishell)
{
	minishell_dispose(minishell);
	minishell_free(minishell);
}
