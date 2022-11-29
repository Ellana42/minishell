#include "parser.h"

t_token	*parser_get_token(t_parser *parser)
{
	return (tokenizer_get_token(parser->tokenizer, parser->token_i));
}

int	parser_is_eol(t_parser *parser)
{
	t_token *token;
	
	token = parser_get_token(parser);
	if (!token)
		return (1);
	return (token->type == Eol);
}