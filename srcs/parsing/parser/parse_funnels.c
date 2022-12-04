#include "parser.h"

int	parse_out(t_parser *parser)
{
	t_token		*token;

	token = parser_get_token(parser);
	if (!token)
	{
		parser->error = ParserUnknownError;
		return (1);
	}
	if (token->type == Str)
	{
		command_add_out(parser->command, token->str);
		parser_move_cursor(parser);
		parser->state = pParams;
		return (0);
	}
	parser->error = ParserSyntaxError;
	return (1);
}

int	parse_outa(t_parser *parser)
{
	t_token		*token;

	token = parser_get_token(parser);
	if (!token)
	{
		parser->error = ParserUnknownError;
		return (1);
	}
	if (token->type == Str)
	{
		command_add_out_a(parser->command, token->str);
		parser_move_cursor(parser);
		parser->state = pParams;
		return (0);
	}
	parser->error = ParserSyntaxError;
	return (1);
}

int	parse_in(t_parser *parser)
{
	t_token		*token;

	token = parser_get_token(parser);
	if (!token)
	{
		parser->error = ParserUnknownError;
		return (1);
	}
	if (token->type == Str)
	{
		command_add_in(parser->command, token->str);
		parser_move_cursor(parser);
		parser->state = pParams;
		return (0);
	}
	parser->error = ParserSyntaxError;
	return (1);
}

int	parse_ina(t_parser *parser)
{
	t_token		*token;

	token = parser_get_token(parser);
	if (!token)
	{
		parser->error = ParserUnknownError;
		return (1);
	}
	if (token->type == Str)
	{
		command_add_in_a(parser->command, token->str);
		parser_move_cursor(parser);
		parser->state = pParams;
		return (0);
	}
	parser->error = ParserSyntaxError;
	return (1);
}
