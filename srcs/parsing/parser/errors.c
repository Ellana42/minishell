#include "parser.h"

t_parser	*parser_set_error(t_parser *parser, t_parser_error error)
{
	parser->error.error = error;
	if (error == ParserSyntaxError)
	{
		parser->error.err_char = parser_get_token(parser)->current_char;
		printf("the char :%d:\n", (int )parser_get_token(parser)->current_char);
	}
	else
		parser->error.err_char = '\0';
	return (parser);
}

int	parser_set_error_return(t_parser *parser, t_parser_error error)
{
	parser_set_error(parser, error);
	return (1);
}

int	parser_get_error(t_parser *parser)
{
	return (parser->error.error);
}

// TODO deal with translation (newline)
char	parser_get_error_char(t_parser *parser)
{
	return (parser->error.err_char);
}
