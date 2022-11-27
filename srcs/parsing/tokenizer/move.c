#include "tokenizer.h"

int	tokenizer_move_cursor(t_tokenizer *tokenizer)
{
	(tokenizer->cmd_ptr)++;
	(tokenizer->cmd_i)++;
	return (0);
}

int	tokenizer_move_accumulator(t_tokenizer *tokenizer)
{
	(tokenizer->acc_ptr)++;
	(tokenizer->acc_i)++;
	return (0);
}
