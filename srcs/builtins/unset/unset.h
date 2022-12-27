#ifndef UNSET_H
# define UNSET_H

# include "../../libft.h"
# include <stdbool.h>

typedef struct s_data
{
	char	*working_directory;
	char	**env;
}	t_data;

int		unset(t_data *data, char **args);
int		get_env_var_index(char **env, char *var);
int		env_var_nbr(char **env);
bool	is_valid_env_var(char *var);
bool	remove_env_var(t_data *data, int index);

#endif