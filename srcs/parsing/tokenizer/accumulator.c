#include "tokenizer.h"

void	reset_acc(t_tokenizer *tokenizer)
{
	acc_reset(tokenizer->acc);
}

int	tokenizer_is_empty_acc(t_tokenizer *tokenizer)
{
	return (acc_is_empty(tokenizer->acc));
}

int	tokenizer_accumulate(t_tokenizer *tokenizer)
{
	acc_accumulate(tokenizer->acc, *(tokenizer->cmd_ptr));
	tokenizer_move_cursor(tokenizer);
	return (0);
}

int	tokenizer_acc_concat(t_tokenizer *tokenizer, char *str)
{
	acc_concat(tokenizer->acc, str);
	return (0);
}
