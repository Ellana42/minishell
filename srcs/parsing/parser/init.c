#include "parser.h"

t_parser	*parser_alloc(void)
{
	t_parser	*parser;

	parser = (t_parser *)malloc(sizeof(t_parser));
	return (parser);
}

int	parser_init(t_parser *parser, t_tokenizer *tokenizer)
{
	parser->command = NULL;
	parser->commands = commands_alloc();
	commands_init(parser->commands);
	parser->state = pStart;
	parser->tokenizer = tokenizer;
	parser->token_i = 0;
	return (0); // errors
}

void parser_dispose(t_parser *parser)
{
	free(parser->command);
	commands_destroy(parser->commands);
}

void parser_free(t_parser *parser)
{
	free(parser);
}

void	parser_destroy(t_parser *parser)
{
	parser_dispose(parser);
	parser_free(parser);
}
