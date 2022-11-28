#include "token.h"

void	token_print(t_token *token)
{
	if (token->type == Pipe)
		printf(":pipe:\n");
	if (token->type == Str)
		printf(":string:%s\n", token->str);
}
