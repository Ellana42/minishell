/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:15:38 by lsalin            #+#    #+#             */
/*   Updated: 2022/11/30 13:23:29 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIG_H
# define BIG_H

# include "libft.h"
# include "libft/includes/ft_printf.h"
# include "libft/includes/libft.h"
# include "execution/pipe/pipex.h"
# include <sys/wait.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
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

char	*find_path(char *cmd, char **envp);
void	first_child(char **argv, char **envp, int pipefd[2], int fd[2]);
void	second_child(char **argv, char **envp, int pipefd[2], int fd[2]);
void	error(void);
void	ft_putstr_fd(char *s, int fd);
void	ft_print_putstr(void);
void	free_strs(char *str, char **strs);
void	close_fd(int pipefd[2], int fd[2]);

#endif