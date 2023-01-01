#include "parser.h"

int	parse_out_no_cmd(t_parser *parser)
{
	t_token		*token;

	token = parser_get_token(parser);
	if (!token)
		return (parser_set_error_return(parser, ParserUnknownError));
	if (token->type == Str)
	{
		command_add_out(parser->command, token->str);
		parser_move_cursor(parser);
		parser->state = pNoCommand;
		return (0);
	}
	return (parser_set_error_return(parser, ParserSyntaxError));
}

int	parse_outa_no_cmd(t_parser *parser)
{
	t_token		*token;

	token = parser_get_token(parser);
	if (!token)
		return (parser_set_error_return(parser, ParserUnknownError));
	if (token->type == Str)
	{
		command_add_out_a(parser->command, token->str);
		parser_move_cursor(parser);
		parser->state = pNoCommand;
		return (0);
	}
	return (parser_set_error_return(parser, ParserSyntaxError));
}

int	parse_in_no_cmd(t_parser *parser)
{
	t_token		*token;

	token = parser_get_token(parser);
	if (!token)
		return (parser_set_error_return(parser, ParserUnknownError));
	if (token->type == Str)
	{
		command_add_in(parser->command, token->str);
		parser_move_cursor(parser);
		parser->state = pNoCommand;
		return (0);
	}
	return (parser_set_error_return(parser, ParserSyntaxError));
}

int	parse_ina_no_cmd(t_parser *parser)
{
	t_token		*token;

	token = parser_get_token(parser);
	if (!token)
		return (parser_set_error_return(parser, ParserUnknownError));
	if (token->type == Str)
	{
		command_add_in_a(parser->command, token->str);
		parser_move_cursor(parser);
		parser->state = pNoCommand;
		return (0);
	}
	return (parser_set_error_return(parser, ParserSyntaxError));
}
