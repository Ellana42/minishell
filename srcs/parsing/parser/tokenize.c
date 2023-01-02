#include "parser.h"

int	parser_tokenize_end(t_parser *parser)
{
	tokenizer_push_eol(parser->tokenizer);
	if (parser->tokenizer->state == Quote)
		return (parser_set_error_return(parser, ParserQuotesUnclosed));
	if (parser->tokenizer->state == SingleQuote)
		return (parser_set_error_return(parser, ParserQuotesUnclosed));
	return (0);
}

int	parser_tokenize_string(t_parser *parser)
{
	while (!tokenizer_eol(parser->tokenizer))
	{
		if (tokenize(parser->tokenizer))
			return (parser_set_error_return(parser, ParserAllocError));
	}
	if (!tokenizer_is_empty_acc(parser->tokenizer))
	{
		tokenizer_push_string(parser->tokenizer);
		reset_acc(parser->tokenizer);
	}
	return (parser_tokenize_end(parser));
}
