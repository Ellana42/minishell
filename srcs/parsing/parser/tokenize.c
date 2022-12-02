#include "parser.h"

int	parser_tokenize_string(t_parser *parser)
{
	while (!tokenizer_eol(parser->tokenizer))
	{
		tokenize(parser->tokenizer);
	}
	if (!tokenizer_is_empty_acc_var(parser->tokenizer))
		tokenizer_acc_concat(parser->tokenizer, getenv(acc_get(parser->tokenizer->acc_var))); 
	if (!tokenizer_is_empty_acc(parser->tokenizer))
	{
		tokenizer_push_string(parser->tokenizer);
		reset_acc(parser->tokenizer);
	}
	tokenizer_push_eol(parser->tokenizer);
	if (parser->tokenizer->state == Quote || parser->tokenizer->state == SingleQuote || parser->tokenizer->state == QuoteV)
		return (1);
	return (0);
}
