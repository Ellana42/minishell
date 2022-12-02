#include "command.h"

void	_print_str(void *s)
{
	printf("%s,", (char *)s);
}

void	_print_str_chain(t_list **lst)	
{
	ft_lstiter(*(lst), &_print_str);
}

void	command_print(t_command *command)
{
	printf("Command :\n");
	printf("- command : %s\n", command->command);
	printf("- args : ");
	_print_str_chain(command->args);
	printf("\n- out : ");
	_print_str_chain(command->out);
	printf("\n- outa : ");
	_print_str_chain(command->out_a);
	printf("\n- in : ");
	_print_str_chain(command->in);
	printf("\n- ina : ");
	_print_str_chain(command->in_a);
	printf("\n");
	printf("\n");
}
