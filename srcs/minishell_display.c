#include "minishell_struct.h"

void	minishell_env_el_print(void *content)
{
	t_dict	*dict;

	dict = (t_dict *)content;
	if (dict->value)
	{
		printf("%s=", dict->key);
		printf("%s\n", dict->value);
	}
}

void	minishell_env_print(t_minishell *minishell)
{
	ft_lstiter(**minishell->env, &minishell_env_el_print);
}

void	minishell_print(t_minishell *minishell, t_bool print_env)
{
	printf("Minishell : \n");
	if (print_env)
		minishell_env_print(minishell);
}
