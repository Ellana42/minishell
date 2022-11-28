#include "parsing.h"

int	main(void)
{
	t_tokenizer *tokenizer;

	char *command = "ls |la";
	printf("The command : %s\n", command);
	
	tokenizer = tokenizer_alloc();
	if (!tokenizer)
		return (1);
	tokenizer_init(tokenizer, command);
	while (!tokenizer_eol(tokenizer))
	{
		tokenize(tokenizer);
	}
	if (!tokenizer_is_empty_acc(tokenizer))
		tokenizer_push_string(tokenizer);
	tokenizer_print_tokens(tokenizer);
	tokenizer_dispose(tokenizer);
	tokenizer_free(tokenizer);
}
