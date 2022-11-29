#include "tokenize.h"

int	tokenize(t_tokenizer *tokenizer)
{
	if (tokenizer->state == Quote)
	{
	}
	if (tokenizer->state == NoQuote)
		tokenize_noquote(tokenizer);
	if (tokenizer->state == SingleQuote)
	{
	}
	if (tokenizer->state == NoQuoteV)
		tokenize_noquotev(tokenizer);
	if (tokenizer->state == QuoteV)
	{
	}
	return (0);
}
