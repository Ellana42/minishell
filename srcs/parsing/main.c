#include "parsing.h"
// TODO all cases tokens
// TODO clean if return 1

int	main(int ac, char **av)
{
	char *command = av[1];
	t_parser *parser;

	printf("\nThe command : %s\n\n", command);

	parser = parse_string(command);
	commands_print(parser->commands);
	parser_destroy(parser);
}
