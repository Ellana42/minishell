#include "tokenize.h"

int	tokenize_noquote_out_a(t_tokenizer *tokenizer)
{
	if (tokenizer_is_empty_acc(tokenizer))
	{
		if (tokenizer_push_outa(tokenizer))
			return (1);
		tokenizer_move_cursor_two(tokenizer);
		return (0);
	}
	if (tokenizer_push_string(tokenizer))
		return (1);
	reset_acc(tokenizer);
	if (tokenizer_push_outa(tokenizer))
		return (1);
	tokenizer_move_cursor_two(tokenizer);
	return (0);
}

int	tokenize_noquote_out(t_tokenizer *tokenizer)
{
	if (tokenizer_get_next_char(tokenizer, 1) == '>')
		return (tokenize_noquote_out_a(tokenizer));
	if (tokenizer_is_empty_acc(tokenizer))
	{
		if (tokenizer_push_out(tokenizer))
			return (1);
		tokenizer_move_cursor(tokenizer);
		return (0);
	}
	if (tokenizer_push_string(tokenizer))
		return (1);
	reset_acc(tokenizer);
	if (tokenizer_push_out(tokenizer))
		return (1);
	tokenizer_move_cursor(tokenizer);
	return (0);
}

int	tokenize_noquote_in_a(t_tokenizer *tokenizer)
{
	if (tokenizer_is_empty_acc(tokenizer))
	{
		if (tokenizer_push_ina(tokenizer))
			return (1);
		tokenizer_move_cursor_two(tokenizer);
		return (0);
	}
	if (tokenizer_push_string(tokenizer))
		return (1);
	reset_acc(tokenizer);
	if (tokenizer_push_ina(tokenizer))
		return (1);
	tokenizer_move_cursor_two(tokenizer);
	return (0);
}

int	tokenize_noquote_in(t_tokenizer *tokenizer)
{
	if (tokenizer_get_next_char(tokenizer, 1) == '<')
		return (tokenize_noquote_in_a(tokenizer));
	if (tokenizer_is_empty_acc(tokenizer))
	{
		if (tokenizer_push_in(tokenizer))
			return (1);
		tokenizer_move_cursor(tokenizer);
		return (0);
	}
	if (tokenizer_push_string(tokenizer))
		return (1);
	reset_acc(tokenizer);
	if (tokenizer_push_in(tokenizer))
		return (1);
	tokenizer_move_cursor(tokenizer);
	return (0);
}
