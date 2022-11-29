
#include "tokenize.h"

int	tokenize_single_quote(t_tokenizer *tokenizer)
{
	printf(":single_quote:\n");
	tokenizer->state = NoQuote;
	return (0);
}
