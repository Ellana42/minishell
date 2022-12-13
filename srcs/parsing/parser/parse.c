#include "parser.h"

int	parse_params_pipe(t_parser *parser)
{
	parser->state = pStart;
	parser_move_cursor(parser);
	commands_push(parser->commands, parser->command);
	parser->command = NULL;
	return (0);
}

int	parse_params_funnel(t_parser *parser, t_parser_state funnel_state)
{
	parser->state = funnel_state;
	parser_move_cursor(parser);
	return (0);
}

int	parse_start(t_parser *parser)
{
	t_token		*token;
	t_command	*command;

	token = parser_get_token(parser);
	if (!token)
		return (parser_set_error_return(parser, ParserUnknownError));
	if (token->type == Pipe || token->type == Eol)
		return (parser_set_error_return(parser, ParserSyntaxError));
	command = command_alloc();
	if (command_init(command, token->str))
		return (parser_set_error_return(parser, ParserAllocError));
	parser->command = command;
	if (token->type == Out)
		return (parse_params_funnel(parser, pOut));
	if (token->type == Outa)
		return (parse_params_funnel(parser, pOuta));
	if (token->type == In)
		return (parse_params_funnel(parser, pIn));
	if (token->type == Ina)
		return (parse_params_funnel(parser, pIna));
	parser_move_cursor(parser);
	parser->state = pParams;
	return (0);
}

int	parse_params(t_parser *parser)
{
	t_token		*token;

	token = parser_get_token(parser);
	if (!token)
		return (parser_set_error_return(parser, ParserUnknownError));
	if (token->type == Str)
	{
		command_add_arg(parser->command, token->str);
		parser_move_cursor(parser);
		return (0);
	}
	if (token->type == Out)
		return (parse_params_funnel(parser, pOut));
	if (token->type == Outa)
		return (parse_params_funnel(parser, pOuta));
	if (token->type == In)
		return (parse_params_funnel(parser, pIn));
	if (token->type == Ina)
		return (parse_params_funnel(parser, pIna));
	if (token->type == Pipe)
		return (parse_params_pipe(parser));
	return (parser_set_error_return(parser, ParserSyntaxError));
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
	return (parser_set_error_return(parser, ParserUnknownError));
}
