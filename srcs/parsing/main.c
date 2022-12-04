#include "parsing.h"
// TODO. test

int	main(int ac, char **av)
{
	char *command = av[1];
	t_parser *parser;

	printf("\nThe command : %s\n\n", command);

	parser = parse_string(command);
	if (parser->error != 0)
		printf("Error %d\n", parser->error);
	else
		commands_print(parser->commands);
	parser_destroy(parser);
	return (0);
}
