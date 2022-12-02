#include "parsing.h"
// TODO check unfinished quotes
// TODO all cases tokens

int	main(int ac, char **av)
{
	t_tokenizer *tokenizer;
	t_parser	*parser;
	int			error;

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
	{
		tokenizer_push_string(tokenizer);
		reset_acc(tokenizer);
	}
	tokenizer_push_eol(tokenizer);
	if (tokenizer->state == Quote || tokenizer->state == SingleQuote || tokenizer->state == QuoteV)
		return (1);
	tokenizer_print_tokens(tokenizer);

	// Parsing
	parser = parser_alloc();	
	if (!parser)
		return (1);
	parser_init(parser, tokenizer);
	error = 0;
	while ((!parser_is_eol(parser)) && (!error))
		error = parse(parser);
	if (parser->command)
	{
		commands_push(parser->commands, parser->command);
		parser->command = NULL;
	}
	commands_print(parser->commands);

	// Cleaning
	parser_dispose(parser);
	parser_free(parser);
	tokenizer_dispose(tokenizer);
	tokenizer_free(tokenizer);
}
