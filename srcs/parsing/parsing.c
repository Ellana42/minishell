#include "parsing.h"
#include "parser/parser.h"

t_parser	*parse_string(char *str)
{
	int			error;
	t_parser	*parser;

	parser = parser_alloc();	
	if (!parser)
		return (NULL);
	if (parser_init(parser, str))
		return (parser);
	if (parser_tokenize_string(parser))
		return (parser);
	parser->error = ParserNoError;
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
