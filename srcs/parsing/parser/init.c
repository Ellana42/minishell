#include "parser.h"

t_parser	*parser_alloc(void)
{
	t_parser	*parser;

	parser = (t_parser *)malloc(sizeof(t_parser));
	if (!parser)
		parser->error = ParserUninitialized;
	return (parser);
}

int	parser_init(t_parser *parser, char *str)
{
	t_tokenizer	*tokenizer;

	tokenizer = tokenizer_alloc();
	parser->commands = commands_alloc();
	if (!tokenizer || !parser->commands)
	{
		parser->error = ParserAllocError;
		return (1);
	}
	if (tokenizer_init(tokenizer, str))
	{
		parser->error = ParserAllocError;
		return (1);
	}
	commands_init(parser->commands);
	parser->command = NULL;
	parser->state = pStart;
	parser->tokenizer = tokenizer;
	parser->token_i = 0;
	parser->error = ParserNotTokenized;
	return (0);
}

void	parser_dispose(t_parser *parser)
{
	free(parser->command);
	commands_destroy(parser->commands);
	tokenizer_destroy(parser->tokenizer);
}

void	parser_free(t_parser *parser)
{
	free(parser);
}

void	parser_destroy(t_parser *parser)
{
	parser_dispose(parser);
	parser_free(parser);
}
