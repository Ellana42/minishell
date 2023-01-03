#include "parser.h"

t_parser	*parser_set_error(t_parser *parser, t_parser_error error)
{
	t_token	*current_token;

	parser->error.error = error;
	if (error == ParserSyntaxError)
	{
		current_token = parser_get_token(parser);
		parser->error.err_token = current_token;
	}
	else
		parser->error.err_token = NULL;
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
t_token	*parser_get_error_token(t_parser *parser)
{
	return (parser->error.err_token);
}

void	parser_print_error_token(t_parser *parser)
{
	token_print_literal(parser->error.err_token);
}
