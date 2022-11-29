#include "tokenize.h"

int	tokenize(t_tokenizer *tokenizer)
{
	if (tokenizer->state == NoQuote)
	{
		tokenize_noquote(tokenizer);
		/* printf("Switch to noquote\n"); */
	}
	if (tokenizer->state == Quote)
	{
		tokenize_quote(tokenizer);
		/* printf("Switch to Quote\n"); */
	}
	if (tokenizer->state == SingleQuote)
	{
		tokenize_single_quote(tokenizer);
		/* printf("Switch to SingleQuote\n"); */
	}
	if (tokenizer->state == NoQuoteV)
	{
		tokenize_noquotev(tokenizer);
		/* printf("Switch to NoQuoteV\n"); */
	}
	if (tokenizer->state == QuoteV)
	{
		tokenize_quotev(tokenizer);
		/* printf("Switch to QuoteV\n"); */
	}
	return (0);
}
