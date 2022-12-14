#ifndef EXECUTABLE_H
# define EXECUTABLE_H

# include "../../parsing/parsing.h"

typedef	int *t_pipe;

typedef struct s_executable {
	t_command	*command;
	t_pipe		in_pipe;
	t_pipe		out_pipe;
	int			*in_files;
	int			*out_files;
}	t_executable;

int				init_pipes(int ***pipes, int commands_size);
void			print_pipes(int **pipes, int commands_size);
int				get_fd_in(int **pipes, int index_cmd);
int				get_fd_out(int **pipes, int index_cmd, int commands_size);
int				close_unused_fds(int **pipes, int index_cmd, int commands_size);
int				pipes_get_size(int **pipes);
int				get_in_table(t_command *cmd, int **in_table, char **file_name);
int				get_out_table(t_command *cmd, int **out_table);
int				clean_table_out(int **out_table, t_command *cmd);
int				clean_table_in(int **in_table, t_command *cmd);
int				executable_init(t_executable *executable, t_command *command, int **pipes, int index);
t_executable	*executable_alloc(void);

#endif
