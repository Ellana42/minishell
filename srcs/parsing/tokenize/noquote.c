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
	var = glob_getenv_var(acc_get(tokenizer->acc_var));
	if (var)
	{
		if (tokenizer_acc_concat(tokenizer, var))
			return (1);
	}
	reset_acc_var(tokenizer);
	return (0);
}

int	tokenize_noquote(t_tokenizer *tokenizer)
{
	if (tokenizer_get_char(tokenizer) == '$')
		return (tokenize_noquote_dollar(tokenizer));
	if (tokenizer_get_char(tokenizer) == '"')
		return (tokenize_noquote_quote(tokenizer));
	if (tokenizer_get_char(tokenizer) == '\'')
		return (tokenize_noquote_squote(tokenizer));
	if (tokenizer_get_char(tokenizer) == '|')
		return (tokenize_noquote_pipe(tokenizer));
	if (tokenizer_get_char(tokenizer) == '>')
		return (tokenize_noquote_out(tokenizer));
	if (tokenizer_get_char(tokenizer) == '<')
		return (tokenize_noquote_in(tokenizer));
	if (tokenizer_get_char(tokenizer) == ' ')
		return (tokenize_noquote_space(tokenizer));
	tokenizer_accumulate(tokenizer);
	return (0);
}
