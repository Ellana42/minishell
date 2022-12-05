/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 12:47:53 by lsalin            #+#    #+#             */
/*   Updated: 2022/12/05 15:36:13 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include "srcs/execution/libft/includes/libft.h"

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <string.h>
# include <errno.h>

typedef struct s_data
{
	int		argc;
    char	**argv;
    char	**envp;
    char	**array_of_paths;
	char	*path_ultime;
    int		nbr_commands;
    int		*pipefd;
	int		heredoc;
	int		fd_in;
	int		fd_out;
	int		child;
	int		*pids;
}		t_data;

// PIPEX

char    *get_cmd(char *cmd, t_data *data);
t_data	init_struct(int ac, char **av, char **envp);
void	get_input_file(t_data *data);
void	get_output_file(t_data *data);
void	get_heredoc(t_data *data);
void	error(int error_status, t_data *data);
int		msg(char *str1, char *str2, char *str3, int erno);
void	close_fds(t_data *data);
void	free_strs(char *str, char **strs);

// GNL

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE BUFSIZ
# endif

# if BUFFER_SIZE > 9223372036854775806
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

char	*get_next_line(int fd);
void	ft_read_line(int fd, char **keep, char **tmp);
char	*ft_parse_line(char **keep, char **tmp);
char	*get_before_newline(const char *s);
char	*get_after_newline(const char *s);
int		contains_newline(const char *s);
char	*join_strs(const char *s1, const char *s2);
void	*ft_malloc_zero(size_t count, size_t size);
void	free_strs_three(char **str, char **str2, char **str3);

#endif