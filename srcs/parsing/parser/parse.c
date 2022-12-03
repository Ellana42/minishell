#include "parser.h"


int	parse_start(t_parser *parser)
{
	t_token		*token;
	t_command *command;
	
	token = parser_get_token(parser);
	if (!token)
	{
		parser->error =	ParserUnknownError;
		return (1);
	}
	if (token->type == Str) 
	{
		command = command_alloc();
		command_init(command, token->str);
		parser->command = command;
		parser_move_cursor(parser);
		parser->state = pParams;
		return (0);
	}
	parser->error = ParserSyntaxError;
	return (1);
}

int	parse_params(t_parser *parser)
{
	t_token		*token;
	
	token = parser_get_token(parser);
	if (!token)
	{
		parser->error =	ParserUnknownError;
		return (1);
	}
	if (token->type == Str) 
	{
		command_add_arg(parser->command, token->str);
		parser_move_cursor(parser);
		return (0);
	}
	if (token->type == Out) 
	{
		parser->state = pOut;
		parser_move_cursor(parser);
		return (0);
	}
	if (token->type == Outa) 
	{
		parser->state = pOuta;
		parser_move_cursor(parser);
		return (0);
	}
	if (token->type == In) 
	{
		parser->state = pIn;
		parser_move_cursor(parser);
		return (0);
	}
	if (token->type == Ina) 
	{
		parser->state = pIna;
		parser_move_cursor(parser);
		return (0);
	}
	if (token->type == Pipe) 
	{
		parser->state = pStart;
		parser_move_cursor(parser);
		commands_push(parser->commands, parser->command);
		parser->command = NULL;
		return (0);
	}
	parser->error = ParserSyntaxError;
	return (1);
}

int	parse_out(t_parser *parser)
{
	t_token		*token;
	
	token = parser_get_token(parser);
	if (!token)
	{
		parser->error =	ParserUnknownError;
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
		parser->error =	ParserUnknownError;
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
		parser->error =	ParserUnknownError;
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
		parser->error =	ParserUnknownError;
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

int	parse(t_parser *parser)
{
	if (parser->state == pStart)
		return (parse_start(parser));
	if (parser->state == pParams)
		return (parse_params(parser));
	if (parser->state == pOut)
		return (parse_out(parser));
	if (parser->state == pOuta)
		return (parse_outa(parser));
	if (parser->state == pIn)
		return (parse_in(parser));
	if (parser->state == pIna)
		return (parse_ina(parser));
	parser->error = ParserUnknownError;
	return (1);
}
