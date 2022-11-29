#include "tokenizer.h"

int	tokenizer_push_out(t_tokenizer *tokenizer)
{
	t_token	*token;

	token = token_alloc();
	token_init(token, Out, NULL);
	ft_lstadd_back(tokenizer->tokens, ft_lstnew((void *)token));
	return (0);
}

int	tokenizer_push_outa(t_tokenizer *tokenizer)
{
	t_token	*token;

	token = token_alloc();
	token_init(token, Outa, NULL);
	ft_lstadd_back(tokenizer->tokens, ft_lstnew((void *)token));
	return (0);
}

int	tokenizer_push_in(t_tokenizer *tokenizer)
{
	t_token	*token;

	token = token_alloc();
	token_init(token, In, NULL);
	ft_lstadd_back(tokenizer->tokens, ft_lstnew((void *)token));
	return (0);
}

int	tokenizer_push_ina(t_tokenizer *tokenizer)
{
	t_token	*token;

	token = token_alloc();
	token_init(token, Ina, NULL);
	ft_lstadd_back(tokenizer->tokens, ft_lstnew((void *)token));
	return (0);
}
