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

#endif
