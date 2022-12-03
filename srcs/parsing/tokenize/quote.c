#include "tokenize.h"

int	tokenize_quotev(t_tokenizer *tokenizer)
{
	char	c;

	c = tokenizer_get_char(tokenizer);
	if (ft_isalnum(c) || c == '_')
	{
		tokenizer_accumulate_var(tokenizer);
		return (0);
	}
	tokenizer->state = Quote;
	if (tokenizer_acc_concat(tokenizer, getenv(acc_get(tokenizer->acc_var)))) 
		return (1);
	reset_acc_var(tokenizer);
	return (0);
}

int	tokenize_quote(t_tokenizer *tokenizer)
{
	if (tokenizer_get_char(tokenizer) == '\"')
	{
		tokenizer->state = NoQuote;
		tokenizer_move_cursor(tokenizer);
		return (0);
	}
	if (tokenizer_get_char(tokenizer) == '$' && tokenizer_get_next_char(tokenizer, 1) == '?')
	{
		// TODO gérer ? attention taille acc 
		tokenizer_move_cursor(tokenizer);
		tokenizer_move_cursor(tokenizer);
		return (0);
	}
	if (tokenizer_get_char(tokenizer) == '$')
	{
		tokenizer->state = QuoteV;
		tokenizer_move_cursor(tokenizer);
		return (0);
	}
	tokenizer_accumulate(tokenizer);
	return (0);
}
