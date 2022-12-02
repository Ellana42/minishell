#include "parsing.h"
// TODO all cases tokens
// TODO clean if return 1

t_tokenizer	*tokenize_string(char *str)
{
	t_tokenizer *tokenizer;

	tokenizer = tokenizer_alloc();
	if (!tokenizer)
		return (NULL);
	tokenizer_init(tokenizer, str);
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
		return (NULL);
	return (tokenizer);
}

t_parser	*parse_string(char *str)
{
	int			error;
	t_parser	*parser;
	t_tokenizer	*tokenizer;

	tokenizer = tokenize_string(str);
	parser = parser_alloc();	
	if (!parser)
		return (NULL);
	parser_init(parser, tokenizer);
	error = 0;
	while ((!parser_is_eol(parser)) && (!error))
		error = parse(parser);
	if (parser->command)
	{
		commands_push(parser->commands, parser->command);
		parser->command = NULL;
	}
	return (parser);
}

