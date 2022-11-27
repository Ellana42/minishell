#include "parsing.h"

int	main(void)
{
	t_tokenizer tokenizer;
	char command[7] = "ls |la";
	printf("The command : %s\n", command);
	
	tokenizer_init(&tokenizer, command);
	while (!tokenizer_eol(&tokenizer))
	{
		tokenize(&tokenizer);
	}
	if (!tokenizer_is_empty_acc(&tokenizer))
		tokenizer_push_string(&tokenizer);
}
