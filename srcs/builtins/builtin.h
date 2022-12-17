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

#endif