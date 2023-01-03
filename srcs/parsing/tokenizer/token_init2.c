#include "token.h"

int	token_init_in(t_token *token, int index, char c)
{
	token->type = In;
	token->str = NULL;
	token->current_index = index;
	token->current_char = c;
	return (0);
}

int	token_init_ina(t_token *token, int index, char c)
{
	token->type = Ina;
	token->str = NULL;
	token->current_index = index;
	token->current_char = c;
	return (0);
}
