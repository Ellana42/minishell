#include "tokenizer.h"

int	tokenizer_push_pipe(t_tokenizer *tokenizer)
{
	t_token	*token;

	token = token_alloc();
	if (token_init(token, Pipe, NULL))
		return (1);
	ft_lstadd_back(tokenizer->tokens, ft_lstnew((void *)token));
	return (0);
}

int	tokenizer_push_string(t_tokenizer *tokenizer)
{
	t_token	*token;

	token = token_alloc();
	if (token_init(token, Str, tokenizer->acc->acc))
		return (1);
	ft_lstadd_back(tokenizer->tokens, ft_lstnew((void *)token));
	return (0);
}

int	tokenizer_push_eol(t_tokenizer *tokenizer)
{
	t_token	*token;

	token = token_alloc();
	if (token_init(token, Eol, NULL))
		return (1);
	ft_lstadd_back(tokenizer->tokens, ft_lstnew((void *)token));
	return (0);
}
