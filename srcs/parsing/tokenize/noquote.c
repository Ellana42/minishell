#include "tokenize.h"

int	tokenize_noquote(t_tokenizer *tokenizer)
{
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
