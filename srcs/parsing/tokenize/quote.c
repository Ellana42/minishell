#include "tokenize.h"

int	tokenize_quote(t_tokenizer *tokenizer)
{
	printf(":quote:\n");
	tokenizer->state = NoQuote;
	return (0);
}
