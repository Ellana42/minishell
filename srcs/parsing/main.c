#include "parsing.h"

int	main(int ac, char **av)
{
	char		*command = av[1];
	t_parser	*parser;
	int			last_err;

	last_err = 66;
	printf("\nThe command : %s\n\n", command);
	parser = parse_string(command, last_err);
	if (parser->error != 0)
		printf("Error %d\n", parser->error);
	else
		commands_print(parser->commands);
	parser_destroy(parser);
	return (0);
}
