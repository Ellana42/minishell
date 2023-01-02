/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executable.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellana <mtmrkaploun@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:09:14 by ellana            #+#    #+#             */
/*   Updated: 2023/01/02 18:09:30 by ellana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTABLE_H
# define EXECUTABLE_H

# include "../../parsing/parsing.h"

typedef int				*t_pipe;

typedef struct s_executable {
	t_command	*command;
	t_pipe		in_pipe;
	t_pipe		out_pipe;
	int			in_size;
	int			out_size;
	int			**in_files;
	int			*out_files;
}	t_executable;

typedef t_executable	t_exe;

int				init_pipes(int ***pipes, int commands_size);
int				get_fd_in(int **pipes, int index_cmd);
int				get_fd_out(int **pipes, int index_cmd, int commands_size);
int				close_unused_fds(int **pipes, int index_cmd, int commands_size);
int				pipes_get_size(int **pipes);
int				executable_init(t_exe *exe, t_command *cmd, int **pipes, int i);
t_executable	*executable_alloc(void);
void			executable_destroy(t_executable *executable);
int				get_out_table(t_command *cmd, int **out_table, int *out_size);
int				get_in_table(t_command *cmd, int ***table, char **name, int *s);
void			executable_print(void *executable_ptr);
int				executable_close_infiles(t_executable *executable);
int				executable_close_outfiles(t_executable *executable);
int				executable_close_files(t_executable *executable);
int				executable_close_infiles(t_executable *executable);
int				executable_close_outfiles(t_executable *executable);
int				executable_close_unused_infiles(t_executable *executable);
int				executable_close_unused_outfiles(t_executable *executable);
int				executable_get_fds_close(t_executable *executable, int fd[2]);
int				close_pipe(int *fd);
int				close_fd(int fd);
int				_close_in_fd_table(int **table, int table_size);
int				_close_fd_table(int *table, int table_size);
void			print_pipes(int **pipes);

#endif
