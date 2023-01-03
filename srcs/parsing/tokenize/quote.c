#include "tokenize.h"

int	tokenize_quote(t_tokenizer *tokenizer)
{
	tokenizer_set_not_empty_acc(tokenizer);
	if (tokenizer_get_char(tokenizer) == '\"')
	{
		tokenizer->state = NoQuote;
		tokenizer_move_cursor(tokenizer);
		return (0);
	}
	tokenizer_accumulate(tokenizer);
	return (0);
}
