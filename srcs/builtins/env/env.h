#ifndef ENV_H
# define ENV_H

# include "../../libft.h"

typedef struct s_data
{
	char	*working_directory;
	char	**env;
}	t_data;

int env_builtin(t_data *data, char **args);

#endif