#include "tokenize.h"

int	tokenize_quote_dollar(t_tokenizer *tokenizer)
{
	char	*err_num;
	char	c;

	err_num = NULL;
	if (tokenizer_get_next_char(tokenizer, 1) == '?')
	{
		err_num = ft_itoa(tokenizer->last_err);
		if (tokenizer_acc_concat(tokenizer, err_num))
			return (1);
		free(err_num);
		tokenizer_move_cursor(tokenizer);
		tokenizer_move_cursor(tokenizer);
		return (0);
	}
	if (!ft_isalnum(tokenizer_get_next_char(tokenizer, 1)))
	{
		tokenizer_accumulate(tokenizer);
		return (0);
	}
	tokenizer->state = QuoteV;
	tokenizer_move_cursor(tokenizer);
	return (0);
}

int	tokenize_quotev(t_tokenizer *tokenizer)
{
	char	c;
	char	*var;

	c = tokenizer_get_char(tokenizer);
	if (ft_isalnum(c) || c == '_')
	{
		tokenizer_accumulate_var(tokenizer);
		return (0);
	}
	tokenizer->state = Quote;
	var = glob_getenv_var(acc_get(tokenizer->acc_var));
	if (var)
	{
		if (tokenizer_acc_concat(tokenizer, var))
			return (1);
		free(var);
	}
	reset_acc_var(tokenizer);
	return (0);
}

int	tokenize_quote(t_tokenizer *tokenizer)
{
	tokenizer_set_not_empty_acc(tokenizer);
	if (tokenizer_get_char(tokenizer) == '\"')
	{
		tokenizer->state = NoQuote;
		tokenizer_move_cursor(tokenizer);
		return (0);
	}
	if (tokenizer_get_char(tokenizer) == '$')
		return (tokenize_quote_dollar(tokenizer));
	tokenizer_accumulate(tokenizer);
	return (0);
}
