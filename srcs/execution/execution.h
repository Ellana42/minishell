#ifndef EXECUTION_H
# define EXECUTION_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <limits.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <stdbool.h>
# include "../../libft/includes/libft.h"
# include "executable/executable.h"
# include "executables/executables.h"
# include "../glob.h"
# include "int_list/int_list.h"

typedef struct s_execution {
	t_executable	*current_executable;
	t_executables	*executables;
	int				executable_index;
	int				**pipes;
	int				executables_size;
	t_intlist		**pids;
	char			**envp;
}	t_execution;

typedef struct s_str_table {
	char	**table;
	int		size;
}	t_str_table;

int				init_pipes(int ***pipes, int commands_size);
void			print_pipes(int **pipes, int commands_size);
int				get_fd_in(int **pipes, int index_cmd);
int				get_fd_out(int **pipes, int index_cmd, int commands_size);
int				close_unused_fds(int **pipes, int index_cmd, int commands_size);
int				pipes_get_size(int **pipes);
void			print_pipe(int *pipe);
t_execution		*execution_alloc(void);
void			execution_print(t_execution *execution);
int				execution(t_commands *commands, char **envp);
void			execution_destroy(t_execution *execution);
void			free_pipes(int **pipes, int commands_size);
t_executable	*execution_get_executable_i(t_execution *execution, int index);
int				execution_close(t_execution *execution);
int				execution_close_unused_pipes(t_execution *execution, int index);
int				execution_close_unused(t_execution *execution, int index);
int				close_fd(int fd);
t_executable	*execution_get_current(t_execution *execution);
void			execution_move(t_execution *execution);
int				close_pipe(int *fd);
void			error(int error_status);
int				msg(char *str1, char *str2, char *str3, int erno);
void			free_strs(char *str, char **array_of_strs);
char			*get_user_cmd(char *cmd, char **envp, int *errnum);
t_command		*execution_get_current_command(t_execution *execution);
int				execution_init(t_execution *exec, t_commands *cmds, char **env);
char			**execution_get_env(t_execution *execution);
int				execution_launch_exec(t_execution *execution);
int				execution_fork_process(t_execution *execution);
int				execution_dup_out(int fd_out);
int				execution_dup_in(int fd_in);
int				is_dir(char *path);
int				execution_get_heredoc(char *delimiter, int fd[2]);
int				execution_store_pid(t_execution *execution, int pid);
int				execution_pop_pid(t_execution *execution, int *pid);
int				execution_get_pid(t_execution *execution);

#endif
