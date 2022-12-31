#include "glob.h"

extern t_glob	*g_glob;

void	env_el_print(void *content)
{
	t_dict	*dict;

	dict = (t_dict *)content;
	if (dict->value)
	{
		printf("%s=", dict->key);
		printf("%s\n", dict->value);
	}
}

void	env_print(void)
{
	ft_lstiter(**g_glob->env, &env_el_print);
}

void	env_el_destroy(void *content)
{
	t_dict	*dict;

	dict = (t_dict *)content;
	free(dict->key);
	free(dict->value);
	free(dict);
}

// Re-alloue de la memoire pour un nouvel env
// Retourne un pointeur sur le nouvel env ou NULL
int	realloc_env_var(char *env_line, t_list **new_env)
{
	t_dict			*new_el;
	t_list			*new_el_lst;
	int				i;

	i = 0;
	new_el = (t_dict *)malloc(sizeof(t_dict));
	if (!new_el)
		return (1);
	while (ft_isalnum(env_line[i]) || env_line[i] == '_')
		i++;
	if (str_store(&(new_el->key), env_line, 0, i))
		return (1);
	if (str_store(&(new_el->value), env_line, i + 1, ft_strlen(env_line)))
		return (1);
	new_el_lst = ft_lstnew((void *)new_el);
	if (!new_el_lst)
		return (1);
	ft_lstadd_back(new_env, new_el_lst);
	return (0);
}

int	realloc_env_vars(char **envp, t_list ***new_env)
{
	int				i;

	*new_env = ft_lstinit();
	if (!new_env)
		return (1);
	i = 0;
	while (envp[i])
	{
		if (realloc_env_var(envp[i], *new_env))
			return (1);
		i++;
	}
	return (0);
}
