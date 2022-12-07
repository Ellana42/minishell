/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 12:47:53 by lsalin            #+#    #+#             */
/*   Updated: 2022/12/07 11:16:44 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <string.h>
# include <errno.h>

# include "get_next_line.h"
# include "../../libft/includes/ft_printf.h"
# include "../../libft/includes/libft.h"
# include "../parsing/parsing.h"

typedef struct s_data
{
	char		**envp;
	char		**argv;
	int			argc;
	int			heredoc;
	int			fd_in;
	int			fd_out;
	int			*pipefd;
	int			nbr_commands;
	int			child;
	int			*pids;
	char		**commands_options;
	char		*cmd_path;
	t_commands	*commands;
}	t_data;

t_commands	init_struct(t_commands *commands);
char		*get_user_cmd(char *cmd, t_commands	*commands);
void		error(int error_status, t_commands *commands);
int			msg(char *str1, char *str2, char *str3, int erno);
void		close_fds(t_commands *commands);
void		free_strs(char *str, char **array_of_strs);
void		get_input_file(t_commands *commands);
void		get_output_file(t_commands *commands);
void		get_heredoc(t_commands *commands);

#endif
