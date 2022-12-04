#include "tokenizer.h"

int	tokenizer_push_out(t_tokenizer *tokenizer)
{
	t_token	*token;
	t_list	*lst;

	token = token_alloc();
	if (token_init(token, Out, NULL))
		return (1);
	lst = ft_lstnew((void *)token);
	if (!lst)
		return (1);
	ft_lstadd_back(tokenizer->tokens, lst);
	return (0);
}

int	tokenizer_push_outa(t_tokenizer *tokenizer)
{
	t_token	*token;
	t_list	*lst;

	token = token_alloc();
	if (token_init(token, Outa, NULL))
		return (1);
	lst = ft_lstnew((void *)token);
	if (!lst)
		return (1);
	ft_lstadd_back(tokenizer->tokens, lst);
	return (0);
}

int	tokenizer_push_in(t_tokenizer *tokenizer)
{
	t_token	*token;
	t_list	*lst;

	token = token_alloc();
	if (token_init(token, In, NULL))
		return (1);
	lst = ft_lstnew((void *)token);
	if (!lst)
		return (1);
	ft_lstadd_back(tokenizer->tokens, lst);
	return (0);
}

int	tokenizer_push_ina(t_tokenizer *tokenizer)
{
	t_token	*token;
	t_list	*lst;

	token = token_alloc();
	if (token_init(token, Ina, NULL))
		return (1);
	lst = ft_lstnew((void *)token);
	if (!lst)
		return (1);
	ft_lstadd_back(tokenizer->tokens, lst);
	return (0);
}
