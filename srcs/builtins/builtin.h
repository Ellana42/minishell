#ifndef BUILTIN_H
# define BUILTIN_H

# define PATH_MAX 4096
# include <stdbool.h>
# include "../execution/execution.h"

typedef struct s_data
{
	char	*working_directory;
	char	**env;
}	t_data;

int			env(t_data *data, char **args);
int			export(t_data *data, char **args)
int			unset(t_data *data, char **args);
int			get_env_var_index(char **env, char *var);
int			env_var_nbr(char **env);
static char	**realloc_env_vars(t_data *data, int size);
bool		is_valid_env_var_keys(char *var);
bool		remove_env_var(t_data *data, int index);

#endif