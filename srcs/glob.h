#ifndef GLOB_H
# define GLOB_H

# include "../libft/includes/libft.h"
# include "execution/int_list/int_list.h"

typedef struct s_glob {
	int		activated;
	t_intlist	**pids;
}	t_glob;

int	glob_init();

#endif
