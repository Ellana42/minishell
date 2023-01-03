#include "command.h"

void	command_print(t_command *command)
{
	printf("Command :\n");
	printf("- command : %s\n", command->command);
	printf("- args : ");
	print_str_chain(*command->args);
	printf("\n- out : ");
	print_funnel_chain(*command->out);
	printf("\n- in : ");
	print_funnel_chain(*command->in);
	printf("\n");
	printf("\n");
}
