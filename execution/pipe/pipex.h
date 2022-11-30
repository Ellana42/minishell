/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 10:39:58 by lsalin            #+#    #+#             */
/*   Updated: 2022/11/30 13:15:19 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <sys/wait.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>

typedef struct s_command{
	char *command;
	char **args;
	char **out; // pour > 
	char **out_a; // pour >>
	char **in; // pour < 
	char **in_a; // pour <<
	int	piped; // est-ce que tu passes à la suivante
}   t_command;

char	*find_path(char *cmd, char **envp);
void	first_child(char **argv, char **envp, int pipefd[2], int fd[2]);
void	second_child(char **argv, char **envp, int pipefd[2], int fd[2]);
void	error(void);
void	ft_putstr_fd(char *s, int fd);
void	ft_print_putstr(void);
void	free_strs(char *str, char **strs);
void	close_fd(int pipefd[2], int fd[2]);

#endif