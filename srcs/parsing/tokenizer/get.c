#include "tokenizer.h"

char tokenizer_get_char(t_tokenizer *tokenizer)
{
	return (*(tokenizer->cmd_ptr));
}

char tokenizer_get_next_char(t_tokenizer *tokenizer, int s)
{
	// TODO Gestion d'erreur 
	return ((tokenizer->cmd_ptr)[s]);
}
