#include "tokenize.h"

int	tokenize_noquotev(t_tokenizer *tokenizer)
{
	char	c;
	char	*var;

	c = tokenizer_get_char(tokenizer);
	if (ft_isalnum(c) || c == '_')
	{
		tokenizer_accumulate_var(tokenizer);
		return (0);
	}
	tokenizer->state = NoQuote;
	var = getenv(acc_get(tokenizer->acc_var));
	if (tokenizer_acc_concat(tokenizer, var))
		return (1);
	reset_acc_var(tokenizer);
	return (0);
}

int	tokenize_noquote(t_tokenizer *tokenizer)
{
	if (tokenizer_get_char(tokenizer) == '$')
	{
		if (tokenizer_get_next_char(tokenizer, 1) == '?')
		{
			// TODO gérer ? attention taille acc 
			tokenizer_move_cursor(tokenizer);
			tokenizer_move_cursor(tokenizer);
			return (0);
		}
		tokenizer->state = NoQuoteV;
		tokenizer_move_cursor(tokenizer);
		return (0);
	}
	if (tokenizer_get_char(tokenizer) == '"')
	{
		tokenizer->state = Quote;
		tokenizer_move_cursor(tokenizer);
		return (0);
	}
	if (tokenizer_get_char(tokenizer) == '\'')
	{
		tokenizer->state = SingleQuote;
		tokenizer_move_cursor(tokenizer);
		return (0);
	}
	if (tokenizer_get_char(tokenizer) == '|')
	{
		if (tokenizer_is_empty_acc(tokenizer))
		{
			if (tokenizer_push_pipe(tokenizer))
				return (1);
			tokenizer_move_cursor(tokenizer);
			return (0);
		}
		if (tokenizer_push_string(tokenizer))
			return (1);
		reset_acc(tokenizer);
		if (tokenizer_push_pipe(tokenizer))
			return (1);
		tokenizer_move_cursor(tokenizer);
		return (0);
	}
	if (tokenizer_get_char(tokenizer) == '|')
	{
	}
	if (tokenizer_get_char(tokenizer) == '>')
	{
		if (tokenizer_get_next_char(tokenizer, 1) == '>')
		{
			if (tokenizer_is_empty_acc(tokenizer))
			{
				if (tokenizer_push_outa(tokenizer))
					return (1);
				tokenizer_move_cursor(tokenizer);
				tokenizer_move_cursor(tokenizer);
				return (0);
			}
			if (tokenizer_push_string(tokenizer))
				return (1);
			reset_acc(tokenizer);
			if (tokenizer_push_outa(tokenizer))
				return (1);
			tokenizer_move_cursor(tokenizer);
			tokenizer_move_cursor(tokenizer);
			return (0);
		}
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
	if (tokenizer_get_char(tokenizer) == '<')
	{
		if (tokenizer_get_next_char(tokenizer, 1) == '<')
		{
			if (tokenizer_is_empty_acc(tokenizer))
			{
				if (tokenizer_push_ina(tokenizer))
					return (1);
				tokenizer_move_cursor(tokenizer);
				tokenizer_move_cursor(tokenizer);
				return (0);
			}
			if (tokenizer_push_string(tokenizer))
				return (1);
			reset_acc(tokenizer);
			if (tokenizer_push_ina(tokenizer))
				return (1);
			tokenizer_move_cursor(tokenizer);
			tokenizer_move_cursor(tokenizer);
			return (0);
		}
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
	if (tokenizer_get_char(tokenizer) == ' ')
	{
		if (tokenizer_is_empty_acc(tokenizer))
		{
			tokenizer_move_cursor(tokenizer);
			return (0);
		}
		if (tokenizer_push_string(tokenizer))
			return (1);
		reset_acc(tokenizer);
		tokenizer_move_cursor(tokenizer);
		return (0);
	}
	tokenizer_accumulate(tokenizer);
	return (0);
}
