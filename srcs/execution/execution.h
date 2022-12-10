/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 12:47:53 by lsalin            #+#    #+#             */
/*   Updated: 2022/12/10 15:06:21 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <string.h>
# include <errno.h>

# include "../../libft/includes/ft_printf.h"
# include "../../libft/includes/libft.h"
# include "../parsing/parsing.h"

typedef struct s_data
{
	char		**envp;
	char		**argv;
	int			argc;
	int			*pipefd;
	t_commands	*commands;
}	t_data;

int			pipex_launch(t_commands *commands, char **envp);
t_data		init_struct(t_commands *commands, char **envp);
void		error(int error_status, t_data *data);
int			msg(char *str1, char *str2, char *str3, int erno);
void		close_fds(t_data *data);
void		free_strs(char *str, char **array_of_strs);
char		*get_user_cmd(char *cmd, t_data *data);
void		print_struct(t_data data);

#endif
