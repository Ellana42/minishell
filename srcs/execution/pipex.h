/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 12:47:53 by lsalin            #+#    #+#             */
/*   Updated: 2022/12/07 15:21:46 by mkaploun         ###   ########.fr       */
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

t_data		init_struct(t_commands *commands, char **envp);
char		*get_user_cmd(char *cmd, t_data	*data);
void		error(int error_status, t_data *data);
int			msg(char *str1, char *str2, char *str3, int erno);
void		close_fds(t_data *data);
void		free_strs(char *str, char **array_of_strs);
void		get_input_file(t_data *data);
void		get_output_file(t_data *data);
void		get_heredoc(t_data *data);
int			pipex_launch(t_commands *commands, char **envp);

#endif
