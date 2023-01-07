#ifndef EXECUTION_H
# define EXECUTION_H

# include "../error.h"
# include <stdio.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <limits.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <stdbool.h>
# include "../../libft/includes/libft.h"
# include "executable/executable.h"
# include "executables/executables.h"
# include "../glob/glob.h"
# include "int_list/int_list.h"
# include "../builtins/builtins.h"
# include "../minishell_struct.h"

# define MAX_DELIMITER 4096

typedef struct s_str_table {
	char	**table;
	int		size;
}	t_str_table;

int				get_fd_in(int **pipes, int index_cmd);
int				get_fd_out(int **pipes, int index_cmd, int commands_size);
int				close_unused_fds(int **pipes, int index_cmd, int commands_size);
int				pipes_get_size(int **pipes);
void			print_pipe(int *pipe);
t_execution		*execution_alloc(void);
void			execution_print(t_execution *execution);
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
t_command		*execution_get_current_command(t_execution *execution);
int				execution_fork_process(t_execution *execution);
int				execution_dup_out(int fd_out);
int				execution_dup_in(int fd_in);
int				is_dir(char *path);
int				execution_launch_builtin(t_execution *execution);
int				execution_is_builtin(t_execution *execution);
int				execution_is_single_builtin(t_execution *execution);
int				execution_is_command(t_execution *execution);
void			print_pipes(int **pipes);
char			*get_user_cmd(char *cmd, int *errnum);
int				execution_launch_builtin_single(t_execution *execution);
int				execution_launch_exec(t_execution *execution, char *path);
char			*set_error(int *errnum, int err, char *cmd);
int				execution(t_parser *parser, t_minishell *minishell);
int				execution_init(t_execution *execution, t_parser *parser, \
		t_minishell *minishell);
t_minishell		*execution_get_minishell(t_execution *execution);
void			execution_print_full(t_execution *execution);
void			execution_set_terminal(t_execution *execution, int terminal_i);
int				init_pipes(int ***pipes, int commands_size);
int				execution_get_heredoc(t_execution *execution, char *delimiter, \
		t_executable *executable, int index);
int				clean_table_in(int **in_table, t_command *command);
void			executable_destroy(t_executable *executable);
void	close_precedent_infiles(t_executable *executable, int index);
int	close_everything(t_execution *execution, int index);
void	close_pipes(t_execution *execution);
void	eof_err(char *delimiter);
int	get_here_doc(char *delimiter, int fd[2], int len_delimiter, int exit);

#endif
