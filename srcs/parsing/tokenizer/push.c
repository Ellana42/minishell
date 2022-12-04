#include "tokenizer.h"

int	tokenizer_push_pipe(t_tokenizer *tokenizer)
{
	t_token	*token;
	t_list	*lst;

	token = token_alloc();
	if (!token)
		return (1);
	if (token_init(token, Pipe, NULL))
		return (1);
	lst = ft_lstnew((void *)token);
	if (!lst)
		return (1);
	ft_lstadd_back(tokenizer->tokens, lst);
	return (0);
}

int	tokenizer_push_string(t_tokenizer *tokenizer)
{
	t_token	*token;
	t_list	*lst;

	token = token_alloc();
	if (!token)
		return (1);
	if (token_init(token, Str, tokenizer->acc->acc))
		return (1);
	lst = ft_lstnew((void *)token);
	if (!lst)
		return (1);
	ft_lstadd_back(tokenizer->tokens, lst);
	return (0);
}

int	tokenizer_push_eol(t_tokenizer *tokenizer)
{
	t_token	*token;
	t_list	*lst;

	if (!token)
		return (1);
	token = token_alloc();
	if (token_init(token, Eol, NULL))
		return (1);
	lst = ft_lstnew((void *)token);
	if (!lst)
		return (1);
	ft_lstadd_back(tokenizer->tokens, lst);
	return (0);
}
