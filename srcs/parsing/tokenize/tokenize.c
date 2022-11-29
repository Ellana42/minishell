#include "tokenize.h"

int	tokenize_noquotev(t_tokenizer *tokenizer)
{
	char	c;

	c = tokenizer_get_char(tokenizer);
	if (ft_isalnum(c) || c == '_')
	{
		acc_accumulate(tokenizer->acc_var, *(tokenizer->cmd_ptr));
		tokenizer_move_cursor(tokenizer);
		return (0);
	}
	tokenizer->state = NoQuote;
	tokenizer_acc_concat(tokenizer, getenv(acc_get(tokenizer->acc_var))); 
	return (0);
}

int	tokenize_noquote(t_tokenizer *tokenizer)
{
	if (tokenizer_get_char(tokenizer) == '$' && tokenizer_get_next_char(tokenizer, 1) == '?')
	{
		// TODO gérer ? attention taille acc 
		tokenizer_move_cursor(tokenizer);
		tokenizer_move_cursor(tokenizer);
		return (0);
	}
	if (tokenizer_get_char(tokenizer) == '$')
	{
		tokenizer->state = NoQuoteV;
		tokenizer_move_cursor(tokenizer);
		return (0);
	}
	if (tokenizer_get_char(tokenizer) == '|' && tokenizer_is_empty_acc(tokenizer))
	{
		tokenizer_push_pipe(tokenizer);
		tokenizer_move_cursor(tokenizer);
		return (0);
	}
	if (tokenizer_get_char(tokenizer) == '|')
	{
		tokenizer_push_string(tokenizer);
		reset_acc(tokenizer);
		tokenizer_push_pipe(tokenizer);
		tokenizer_move_cursor(tokenizer);
		return (0);
	}
	if (tokenizer_get_char(tokenizer) == ' ' && tokenizer_is_empty_acc(tokenizer))
	{
		tokenizer_move_cursor(tokenizer);
		return (0);
	}
	if (tokenizer_get_char(tokenizer) == ' ')
	{
		tokenizer_push_string(tokenizer);
		reset_acc(tokenizer);
		tokenizer_move_cursor(tokenizer);
		return (0);
	}
	tokenizer_accumulate(tokenizer);
	return (0);
}

int	tokenize(t_tokenizer *tokenizer)
{
	if (tokenizer->state == Quote)
	{
	}
	if (tokenizer->state == NoQuote)
		tokenize_noquote(tokenizer);
	if (tokenizer->state == SingleQuote)
	{
	}
	if (tokenizer->state == NoQuoteV)
		tokenize_noquotev(tokenizer);
	if (tokenizer->state == QuoteV)
	{
	}
	return (0);
}
