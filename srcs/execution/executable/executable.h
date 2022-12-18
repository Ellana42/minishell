#ifndef EXECUTABLE_H
# define EXECUTABLE_H

# include "../../parsing/parsing.h"

typedef	int *t_pipe;

typedef struct s_executable {
	t_command	*command;
	t_pipe		in_pipe;
	t_pipe		out_pipe;
	size_t		in_size;
	size_t		out_size;
	int			*in_files;
	int			*out_files;
}	t_executable;

int				init_pipes(int ***pipes, int commands_size);
void			print_pipes(int **pipes, int commands_size);
int				get_fd_in(int **pipes, int index_cmd);
int				get_fd_out(int **pipes, int index_cmd, int commands_size);
int				close_unused_fds(int **pipes, int index_cmd, int commands_size);
int				pipes_get_size(int **pipes);
int				executable_init(t_executable *executable, t_command *command, int **pipes, int index);
t_executable	*executable_alloc(void);
void	executable_destroy(t_executable *executable);
int get_out_table(t_command *cmd, int **out_table, int *out_size);
int get_in_table(t_command *cmd, int **in_table, char **file_name, int *in_size);
void	executable_print(void *executable_ptr);
int executable_close_infiles(t_executable *executable);
int executable_close_outfiles(t_executable *executable);
int	executable_close_files(t_executable *executable);
int executable_close_infiles(t_executable *executable);
int executable_close_outfiles(t_executable *executable);
int executable_close_unused_infiles(t_executable *executable);
int executable_close_unused_outfiles(t_executable *executable);
int	executable_get_fds_close(t_executable *executable, int fd[2]);
int	close_pipe(int *fd);
int	close_fd(int fd);

#endif
