#ifndef GLOB_H
# define GLOB_H

# include "../libft/includes/libft.h"
# include "execution/int_list/int_list.h"

typedef struct s_glob {
	int		activated;
	t_intlist	***pids;
}	t_glob;

int	glob_init();
void	glob_print();
int	glob_pop_pid(int *pid);
t_intlist	**glob_get_pids();
void	glob_destroy();
void	glob_set_pids(t_intlist **pids);

#endif
