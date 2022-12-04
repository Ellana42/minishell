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
	if (parser_is_eol(parser))
		return (parser);
	while ((!parser_is_eol(parser)) && (!error))
		error = parse(parser);
	if (parser->error == ParserNoError && parser->state != pParams)
		parser->error = ParserSyntaxError;
	if (parser->command)
	{
		if (commands_push(parser->commands, parser->command))
		{
			parser->error = ParserAllocError;
			return (parser);
		}
		parser->command = NULL;
	}
	return (parser);
}
