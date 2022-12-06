#include "parsing.h"
#include "parser/parser.h"

t_parser	*parse_string(char *str, int last_err)
{
	int			error;
	t_parser	*parser;

	parser = parser_alloc();
	if (!parser)
		return (NULL);
	if (parser_init(parser, str, last_err))
		return (parser);
	if (parser_tokenize_string(parser))
		return (parser);
	parser_set_error(parser, ParserNoError);
	error = 0;
	if (parser_is_eol(parser))
		return (parser);
	while ((!parser_is_eol(parser)) && (!error))
		error = parse(parser);
	if (parser->error == ParserNoError && parser->state != pParams)
		parser_set_error(parser, ParserSyntaxError);
	if (parser->command)
	{
		if (commands_push(parser->commands, parser->command))
			return (parser_set_error(parser, ParserAllocError));
		parser->command = NULL;
	}
	return (parser);
}
