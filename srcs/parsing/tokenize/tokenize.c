#include "tokenize.h"

int	tokenize(t_tokenizer *tokenizer)
{
	if (tokenizer->state == NoQuote)
		return (tokenize_noquote(tokenizer));
	if (tokenizer->state == Quote)
		return (tokenize_quote(tokenizer));
	if (tokenizer->state == SingleQuote)
		return (tokenize_single_quote(tokenizer));
	return (0);
}
