/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:53:52 by mkaploun          #+#    #+#             */
/*   Updated: 2023/01/07 11:56:07 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_token	*parser_get_token(t_parser *parser)
{
	return (tokenizer_get_token(parser->tokenizer, parser->token_i));
}

int	parser_is_eol(t_parser *parser)
{
	t_token	*token;

	token = parser_get_token(parser);
	if (!token)
		return (1);
	return (token->type == Eol);
}
