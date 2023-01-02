/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_funnels_no_cmd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:15:28 by mkaploun          #+#    #+#             */
/*   Updated: 2023/01/02 18:15:29 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
