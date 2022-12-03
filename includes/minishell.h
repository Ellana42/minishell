/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:31:12 by lsalin            #+#    #+#             */
/*   Updated: 2022/12/03 12:20:59 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <errno.h>
# include <fcntl.h>

// PIPEX

typedef struct	s_data
{
	int		argc;
	char	**argv;
	char	**envp;
	char	**array_of_paths;
	char	*path_ultime;
	int		*pipefd;
	int		nbr_commands;
	int		fd_in;
	int		fd_out;
	int		child;
	int		*pids;
	int		here_doc;
}	t_data;

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

#endif