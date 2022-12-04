#include "parser.h"

int	parser_tokenize_string(t_parser *parser)
{
	char	*var;

	while (!tokenizer_eol(parser->tokenizer))
	{
		if (tokenize(parser->tokenizer))
		{
			parser->error = ParserAllocError;
			return (1);
		}
	}
	if (!tokenizer_is_empty_acc_var(parser->tokenizer))
	{
		var = getenv(acc_get(parser->tokenizer->acc_var));
		if (tokenizer_acc_concat(parser->tokenizer, var))
		{
			parser->error = ParserAllocError;
			return (1);
		}
	}
	if (!tokenizer_is_empty_acc(parser->tokenizer))
	{
		tokenizer_push_string(parser->tokenizer);
		reset_acc(parser->tokenizer);
	}
	tokenizer_push_eol(parser->tokenizer);
	if (parser->tokenizer->state == Quote || parser->tokenizer->state == QuoteV)
	{
		parser->error = ParserQuotesUnclosed;
		return (1);
	}
	if (parser->tokenizer->state == SingleQuote)
	{
		parser->error = ParserQuotesUnclosed;
		return (1);
	}
	return (0);
}
