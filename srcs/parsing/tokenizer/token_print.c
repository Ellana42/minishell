#include "token.h"

void	token_print(t_token *token)
{
	char	c;

	c = '\0';
	if (token->type == Pipe)
		printf(":pipe:%d:%c:\n", token->current_index, token->current_char);
	else if (token->type == Out)
		printf(":out:%d:%c:\n", token->current_index, token->current_char);
	else if (token->type == Outa)
		printf(":outa:%d:%c:\n", token->current_index, token->current_char);
	else if (token->type == In)
		printf(":in:%d:%c:\n", token->current_index, token->current_char);
	else if (token->type == Ina)
		printf(":ina:%d:%c:\n", token->current_index, token->current_char);
	else if (token->type == Str)
	{
		c = token->current_char;
		printf(":string:%s:%d:%c:\n", token->str, token->current_index, c);
	}
	else if (token->type == Eol)
		printf(":eol:%d:%c:\n", token->current_index, token->current_char);
	else
		printf(":unrecognised token:\n");
}

void	token_print_literal(t_token *token)
{
	if (token->type == Pipe)
		printf("|");
	else if (token->type == Out)
		printf(">");
	else if (token->type == Outa)
		printf(">>");
	else if (token->type == In)
		printf("<");
	else if (token->type == Ina)
		printf("<<");
	else if (token->type == Str)
		printf("%s", token->str);
	else if (token->type == Eol)
		printf("newline");
	else
		printf("unrecognised token");
}
