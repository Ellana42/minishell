#ifndef GLOB_H
# define GLOB_H

# include "../libft/includes/libft.h"
# include "execution/int_list/int_list.h"
# include "parsing/utils/utils.h"

typedef struct s_export_arg{
	char	*full_arg;
	char	*variable;
	int		operator_;
	char	*value;
}	t_export_arg;

typedef struct s_dict {
	char	*key;
	char	*value;
}	t_dict;

typedef struct s_glob {
	int			activated;
	t_intlist	***pids;
	int			exit_status;
	t_list		***env;
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
void		glob_set_state(int state);
char		*glob_getenv_var(char *var);
void		env_print(void);
int			realloc_env_vars(char **envp, t_list ***new_env);
void		env_el_destroy(void *content);

#endif
