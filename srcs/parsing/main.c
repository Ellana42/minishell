#include "parsing.h"
// TODO check unfinished quotes
// TODO all cases tokens

int	main(int ac, char **av)
{
	t_tokenizer *tokenizer;
	t_parser	*parser;

	char *command = av[1];
	printf("\nThe command : %s\n\n", command);
	
	// Tokenization
	tokenizer = tokenizer_alloc();
	if (!tokenizer)
		return (1);
	tokenizer_init(tokenizer, command);
	while (!tokenizer_eol(tokenizer))
	{
		tokenize(tokenizer);
	}
	if (!tokenizer_is_empty_acc_var(tokenizer))
		tokenizer_acc_concat(tokenizer, getenv(acc_get(tokenizer->acc_var))); 
	if (!tokenizer_is_empty_acc(tokenizer))
		tokenizer_push_string(tokenizer);
	tokenizer_push_eol(tokenizer);
	// TODO check if quotes closed (if state is quotesmth)
	tokenizer_print_tokens(tokenizer);

	// Parsing
	parser = parser_alloc();	
	if (!parser)
		return (1);
	parser_init(parser, tokenizer);

	// Cleaning
	parser_dispose(parser);
	parser_free(parser);
	tokenizer_dispose(tokenizer);
	tokenizer_free(tokenizer);
}
