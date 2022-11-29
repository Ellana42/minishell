#ifndef COMMAND_H
# define COMMAND_H

# include <stdio.h>
# include "../../../libft/includes/libft.h"
# include "../utils/utils.h"

typedef struct s_command{
	char *command;
	t_list **args;
	t_list **out; // pour > 
	t_list **out_a; // pour >>
	t_list **in; // pour < 
	t_list **in_a; // pour <<
	int	piped; // est-ce que tu passes à la suivante
} t_command;

t_command	*command_alloc(void);
int	command_init(t_command *command, char *cmd);
void	_free_string(void *str);
void command_dispose(t_command *command);
void command_free(t_command *command);
void	command_destroy(t_command *command);
char	*_new_str(char *str);
int	command_add_arg(t_command *command, char *str);
int	command_add_out(t_command *command, char *str);
int	command_add_out_a(t_command *command, char *str);
int	command_add_in(t_command *command, char *str);
int	command_add_in_a(t_command *command, char *str);
void	command_print(t_command *command);

#endif
