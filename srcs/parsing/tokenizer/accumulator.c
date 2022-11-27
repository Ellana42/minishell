#include "tokenizer.h"

void	reset_acc(t_tokenizer *tokenizer)
{
	int	i;
	
	i = 0;
	while (i < tokenizer->size)
	{
		(tokenizer->acc)[i] = '\0';
		i++;
	}
	tokenizer->acc_i = 0;	
	tokenizer->acc_ptr = tokenizer->acc;
}

int	tokenizer_is_empty_acc(t_tokenizer *tokenizer)
{
	return (tokenizer->acc_i == 0);
}

int	tokenizer_accumulate(t_tokenizer *tokenizer)
{
	*(tokenizer->acc_ptr) = *(tokenizer->cmd_ptr);
	tokenizer_move_cursor(tokenizer);
	tokenizer_move_accumulator(tokenizer);
	return (0);
}
