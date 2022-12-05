#include "tokenizer.h"

int	tokenizer_eol(t_tokenizer *tokenizer)
{
	return (!(*(tokenizer->cmd_ptr)));
}
