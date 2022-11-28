#include "tokenizer.h"

int	tokenizer_push_pipe(t_tokenizer *tokenizer)
{
	t_token	*token;

	token = token_alloc();
	token_init(token, Pipe, NULL);
	ft_lstadd_back(tokenizer->tokens, ft_lstnew((void *)token));

	printf("pipe\n");
	return (0);
}

int	tokenizer_push_string(t_tokenizer *tokenizer)
{
	t_token	*token;

	token = token_alloc();
	token_init(token, Str, tokenizer->acc);
	ft_lstadd_back(tokenizer->tokens, ft_lstnew((void *)token));

	printf("string : %s\n", tokenizer->acc);
	return (0);
}
