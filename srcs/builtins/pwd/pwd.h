#ifndef PWD_H
# define PWD_H

# include "../../libft.h"

typedef struct s_data
{
	char	*working_directory;
	char	**env;
}	t_data;

int	pwd_builtin(t_data *data, char **args);

#endif