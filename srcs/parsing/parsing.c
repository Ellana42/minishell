#include "parsing.h"
// TODO all cases tokens
// TODO clean if return 1

t_parser	*parse_string(char *str)
{
	int			error;
	t_parser	*parser;

	parser = parser_alloc();	
	if (!parser)
		return (NULL);
	parser_init(parser, str);
	parser_tokenize_string(parser);
	error = 0;
	while ((!parser_is_eol(parser)) && (!error))
		error = parse(parser);
	if (parser->command)
	{
		commands_push(parser->commands, parser->command);
		parser->command = NULL;
	}
	return (parser);
}

