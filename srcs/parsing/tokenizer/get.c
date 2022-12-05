#include "tokenizer.h"

char	tokenizer_get_char(t_tokenizer *tokenizer)
{
	return (*(tokenizer->cmd_ptr));
}

char	tokenizer_get_next_char(t_tokenizer *tokenizer, int s)
{
	if (tokenizer->cmd_i + s > tokenizer->size)
		return (0);
	return ((tokenizer->cmd_ptr)[s]);
}
