#ifndef GLOB_H
# define GLOB_H

# include "../libft/includes/libft.h"
# include "execution/int_list/int_list.h"
# include "parsing/utils/utils.h"

typedef struct s_glob {
	int			activated;
	t_intlist	***pids;
	int			exit_status;
	char		***env;
}	t_glob;

int			glob_pop_pid(int *pid);
t_intlist	**glob_get_pids(void);
void		glob_destroy(void);
void		glob_set_pids(t_intlist **pids);
int			glob_is_running(void);
int			glob_init(int error, char **envp);
void		glob_print(t_bool print_env);
char		**glob_get_env(void);
void		glob_set_env(char **env);
int			glob_get_exit_status(void);
void		glob_set_exit_status(int exit_status);
int			glob_get_state(void);

#endif
