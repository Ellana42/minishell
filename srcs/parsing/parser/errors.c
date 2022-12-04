#include "parser.h"

t_parser	*parser_set_error(t_parser *parser, t_parser_error error)
{
	parser->error = error;
	return (parser);
}

int	parser_get_error(t_parser *parser)
{
	return (parser->error);
}
