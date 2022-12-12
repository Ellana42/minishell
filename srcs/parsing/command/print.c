#include "command.h"

void	command_print(t_command *command)
{
	printf("Command :\n");
	printf("- command : %s\n", command->command);
	printf("- args : ");
	print_str_chain(*command->args);
	printf("\n- out : ");
	print_funnel_chain(*command->out);
	printf("\n- outa : ");
	print_str_chain(*command->out_a);
	printf("\n- in : ");
	print_str_chain(*command->in);
	printf("\n- ina : ");
	print_str_chain(*command->in_a);
	printf("\n");
	printf("\n");
}
