#ifndef EXECUTION_H
# define EXECUTION_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../../libft/includes/libft.h"
# include "executable/executable.h"
# include "executables/executables.h"

typedef struct s_execution {
	t_executable	*current_executable;
	t_executables	*executables;
	int				**pipes;
	size_t			executables_size;
	int				*pids;
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
int	execution_init(t_execution *execution, t_commands *commands, int index);
void	execution_print(t_execution *execution);
int	execution(t_commands *commands, char **envp);
void	execution_destroy(t_execution *execution);
void	free_pipes(int **pipes, int commands_size);

#endif
