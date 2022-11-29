
#include "tokenize.h"

int	tokenize_single_quote(t_tokenizer *tokenizer)
{
	if (tokenizer_get_char(tokenizer) == '\'')
	{
		tokenizer->state = NoQuote;
		tokenizer_move_cursor(tokenizer);
		return (0);
	}
	tokenizer_accumulate(tokenizer);
	return (0);
}
