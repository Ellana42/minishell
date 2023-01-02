/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:15:21 by mkaploun          #+#    #+#             */
/*   Updated: 2023/01/02 18:15:22 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	parse_params_pipe(t_parser *parser)
{
	parser->state = pStart;
	parser_move_cursor(parser);
	commands_push(parser->commands, parser->command);
	parser->command = NULL;
	return (0);
}

int	parse_no_command(t_parser *parser)
{
	t_token		*token;

	token = parser_get_token(parser);
	if (!token)
		return (parser_set_error_return(parser, ParserUnknownError));
	if (token->type == Pipe)
		return (parser_set_error_return(parser, ParserSyntaxError));
	if (token->type == Out)
		return (parse_params_funnel(parser, pOutNoCmd));
	if (token->type == Outa)
		return (parse_params_funnel(parser, pOutaNoCmd));
	if (token->type == In)
		return (parse_params_funnel(parser, pInNoCmd));
	if (token->type == Ina)
		return (parse_params_funnel(parser, pInaNoCmd));
	parser->command->command = ft_strdup(token->str);
	parser_move_cursor(parser);
	parser->state = pParams;
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
		return (parse_params_funnel(parser, pOutNoCmd));
	if (token->type == Outa)
		return (parse_params_funnel(parser, pOutaNoCmd));
	if (token->type == In)
		return (parse_params_funnel(parser, pInNoCmd));
	if (token->type == Ina)
		return (parse_params_funnel(parser, pInaNoCmd));
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

int	parse_tokens(t_parser *parser)
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
	if (parser->state == pNoCommand)
		return (parse_no_command(parser));
	if (parser->state == pOutNoCmd)
		return (parse_out_no_cmd(parser));
	if (parser->state == pOutaNoCmd)
		return (parse_outa_no_cmd(parser));
	if (parser->state == pInNoCmd)
		return (parse_in_no_cmd(parser));
	if (parser->state == pInaNoCmd)
		return (parse_ina_no_cmd(parser));
	return (parser_set_error_return(parser, ParserUnknownError));
}
