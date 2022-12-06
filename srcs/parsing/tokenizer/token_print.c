#include "token.h"

void	token_print(t_token *token)
{
	char	c;

	c = '\0';
	if (token->type == Pipe)
		printf(":pipe:%d:%c:\n", token->current_index, token->current_char);
	if (token->type == Out)
		printf(":out:%d:%c:\n", token->current_index, token->current_char);
	if (token->type == Outa)
		printf(":outa:%d:%c:\n", token->current_index, token->current_char);
	if (token->type == In)
		printf(":in:%d:%c:\n", token->current_index, token->current_char);
	if (token->type == Ina)
		printf(":ina:%d:%c:\n", token->current_index, token->current_char);
	if (token->type == Str)
	{
		c = token->current_char;
		printf(":string:%s:%d:%c:\n", token->str, token->current_index, c);
	}
}
