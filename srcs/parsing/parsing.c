/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:52:40 by mkaploun          #+#    #+#             */
/*   Updated: 2023/01/07 11:52:45 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "parser/parser.h"

t_parser	*parser_initialization(char *str, int last_err)
{
	t_parser	*parser;

	parser = parser_alloc();
	if (!parser)
		return (NULL);
	if (parser_init(parser, str, last_err))
		return (parser);
	if (parser_tokenize_string(parser))
		return (parser);
	parser_set_error(parser, ParserNoError);
	return (parser);
}

t_parser	*parse_string(char *str, int last_err)
{
	int			error;
	t_parser	*parser;

	error = 0;
	parser = parser_initialization(str, last_err);
	if (parser_is_eol(parser))
		return (parser);
	while ((!parser_is_eol(parser)) && (!error))
		error = parse_tokens(parser);
	if (parser->state != pNoCommand && parser->state != pParams)
		parser_set_error(parser, ParserSyntaxError);
	else
		parser_set_error(parser, ParserNoError);
	if (parser->command)
	{
		if (commands_push(parser->commands, parser->command))
			return (parser_set_error(parser, ParserAllocError));
		parser->command = NULL;
	}
	return (parser);
}

t_parser	*parser_print_error(t_parser *parser)
{
	if (parser->error.error == 0)
		return (parser);
	if (parser->error.error == ParserSyntaxError)
	{
		ft_putstr_fd("minishell : syntax error near unexpected token `", 2);
		parser_print_error_token(parser);
		ft_putstr_fd("`\n", 2);
	}
	else
		printf("Error %d\n", parser->error.error);
	return (parser);
}	

t_parser	*parse(char *str, int last_err)
{
	t_parser	*parser;

	parser = parse_string(str, last_err);
	parser = parser_print_error(parser);
	return (parser);
}
