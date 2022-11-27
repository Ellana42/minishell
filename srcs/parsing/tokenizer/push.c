#include "tokenizer.h"

int	tokenizer_push_pipe(t_tokenizer *tokenizer)
{
	printf("pipe\n");
	return (0);
}

int	tokenizer_push_string(t_tokenizer *tokenizer)
{
	printf("string : %s\n", tokenizer->acc);
	return (0);
}
