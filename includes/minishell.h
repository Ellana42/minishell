/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:31:12 by lsalin            #+#    #+#             */
/*   Updated: 2022/12/01 20:52:54 by lsalin           ###   ########.fr       */
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

typedef struct s_parser{
	t_command		*command;
	t_list			**commands;
	t_parser_state	state;
	t_tokenizer		*tokenizer;
	int				token_i;
} t_parser;

typedef struct s_command{
	char *command;
	t_list **args;
	t_list **out; // pour > 
	t_list **out_a; // pour >>
	t_list **in; // pour < 
	t_list **in_a; // pour <<
	int	piped; // est-ce que tu passes à la suivante
} t_command;

typedef struct s_exe
{
	int	pid;
	t_command	*command;
}	t_exe;

// PIPEX

typedef struct s_structure
{
    int     argc;
	int		*pipe;
	int		input;
	int		output;
    char    **argv;
    char    **envp;
    char    *cmd;
	int		nbr_commands;
    int     fd[2];
    int     pipefd[2];
}   t_structure;

// MANDATORY

char	*find_path(t_data *data);
void	first_child(t_data *data);
void	second_child(t_data *data);
void	error(void);
void	ft_print_putstr(void);
void	free_strs(char **str1, char **str2, char **str3);
void	close_fd(t_data *data);

// BONUS
void	create_pipes(t_structure *structure);
void	clean_init_structure(void);
void	redirection_in_out(t_structure *structure);

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