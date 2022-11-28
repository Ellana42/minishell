#include "tokenize.h"

int	tokenize_noquote(t_tokenizer *tokenizer)
{
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
	else if (tokenizer->state == Noquote)
	{
		tokenize_noquote(tokenizer);
	}
	else if (tokenizer->state == SingleQuote)
	{

	}
	return (0);
}
