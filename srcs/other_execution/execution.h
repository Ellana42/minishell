#ifndef EXECUTION_H
# define EXECUTION_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <string.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "../../libft/includes/ft_printf.h"
# include "../../libft/includes/libft.h"
# include "../parsing/parsing.h"
# include "executable/executable.h"

typedef struct s_execution
{
	char		**envp;
	char		**argv;
	int			argc;
	int			*pipefd;
	t_commands	*commands;
}	t_data;

int			pipex_launch(t_commands *commands, char **envp);
t_data		execution_init_struct(t_commands *commands, char **envp);
void		error(int error_status, t_data *data);
int			msg(char *str1, char *str2, char *str3, int erno);
void		close_fds(t_data *data);
void		free_strs(char *str, char **array_of_strs);
char		*get_user_cmd(char *cmd, t_data *data);
void		print_struct(t_data *data);
int			launch_cmd(t_data data, t_command *cmd);
int			launch_child(t_data data, t_command *cmd, int fd[2]);
int			get_here_doc(char *delimiter);

#endif
