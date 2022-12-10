#ifndef COMMAND_H
# define COMMAND_H

# include <stdio.h>
# include "../../../libft/includes/libft.h"
# include "../utils/utils.h"
# include "../lstutils/lstutils.h"

typedef struct s_command{
	char	*command; // 
	t_list	**args;
	t_list	**out; // > ...
	t_list	**out_a; // >> ...
	t_list	**in; // < ...
	t_list	**in_a; // << ...
}	t_command;

t_command	*command_alloc(void);
int			command_init(t_command *command, char *cmd);
void		command_dispose(t_command *command);
void		command_free(t_command *command);
void		command_destroy(t_command *command);
int			command_add_arg(t_command *command, char *str);
int			command_add_out(t_command *command, char *str);
int			command_add_out_a(t_command *command, char *str);
int			command_add_in(t_command *command, char *str);
int			command_add_in_a(t_command *command, char *str);
void		command_print(t_command *command);
char		**command_get_args_table(t_command *command);
char		*command_get_name(t_command *command);
t_list		**command_get_args(t_command *command);
t_list		**command_get_out(t_command *command);
t_list		**command_get_outa(t_command *command);
t_list		**command_get_in(t_command *command);
t_list		**command_get_ina(t_command *command);
void        _free_string(void *str);
char        *_new_str(char *str);

#endif