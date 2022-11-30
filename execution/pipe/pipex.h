/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 10:39:58 by lsalin            #+#    #+#             */
/*   Updated: 2022/11/30 15:15:17 by lsalin           ###   ########.fr       */
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

char	*find_path(char *cmd, char **envp);
void	first_child(char **argv, char **envp, int pipefd[2], int fd[2]);
void	second_child(char **argv, char **envp, int pipefd[2], int fd[2]);
void	error(void);
void	ft_putstr_fd(char *s, int fd);
void	ft_print_putstr(void);
void	free_strs(char *str, char **strs);
void	close_fd(int pipefd[2], int fd[2]);

#endif