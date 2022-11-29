#include "token.h"

void	token_print(t_token *token)
{
	if (token->type == Pipe)
		printf(":pipe:\n");
	if (token->type == Out)
		printf(":out:\n");
	if (token->type == Outa)
		printf(":outa:\n");
	if (token->type == In)
		printf(":in:\n");
	if (token->type == Ina)
		printf(":ina:\n");
	if (token->type == Str)
		printf(":string:%s\n", token->str);
}
