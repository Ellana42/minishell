#ifndef EXECUTION_H
# define EXECUTION_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <limits.h>
# include "../../libft/includes/libft.h"
# include "executable/executable.h"
# include "executables/executables.h"

typedef struct s_execution {
	t_executable	*current_executable;
	t_executables	*executables;
	int				executable_index;
	int				**pipes;
	size_t			executables_size;
	int				*pids;
	char			**envp;
}	t_execution;

int		init_pipes(int ***pipes, int commands_size);
void	print_pipes(int **pipes, int commands_size);
int		get_fd_in(int **pipes, int index_cmd);
int		get_fd_out(int **pipes, int index_cmd, int commands_size);
int		close_unused_fds(int **pipes, int index_cmd, int commands_size);
int		pipes_get_size(int **pipes);
void	print_pipe(int *pipe);
int	get_here_doc(char *delimiter);
t_execution	*execution_alloc(void);
void	execution_print(t_execution *execution);
int	execution(t_commands *commands, char **envp);
void	execution_destroy(t_execution *execution);
void	free_pipes(int **pipes, int commands_size);
t_executable *execution_get_executable_i(t_execution *execution, int index);
int	execution_close(t_execution *execution);
int	execution_close_unused_pipes(t_execution *execution, int index);
int	execution_close_unused(t_execution *execution, int index);
int	close_fd(int fd);
t_executable *execution_get_current(t_execution *execution);
void	execution_move(t_execution *execution);
int	close_pipe(int *fd);
void	error(int error_status);
int	msg(char *str1, char *str2, char *str3, int erno);
void	free_strs(char *str, char **array_of_strs);
char	*get_user_cmd(char *cmd, char **envp);
t_command *execution_get_current_command(t_execution *execution);
int	execution_init(t_execution *execution, t_commands *commands, char **envp);
char **execution_get_env(t_execution *execution);
int	execution_launch_exec(t_execution *execution);

#endif
