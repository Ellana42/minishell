#include "parser.h"

t_parser	*parser_alloc(void)
{
	t_parser	*parser;

	parser = (t_parser *)malloc(sizeof(t_parser));
	return (parser);
}

int	parser_init(t_parser *parser, char *str, int last_err)
{
	t_tokenizer		*tokenizer;
	t_parser_err	err;

	parser->error = err;
	parser_set_error(parser, ParserNotTokenized);
	tokenizer = tokenizer_alloc();
	parser->commands = commands_alloc();
	if (!tokenizer || !parser->commands)
		return (parser_set_error_return(parser, ParserAllocError));
	if (tokenizer_init(tokenizer, str, last_err))
		return (parser_set_error_return(parser, ParserAllocError));
	commands_init(parser->commands);
	parser->command = NULL;
	parser->state = pStart;
	parser->tokenizer = tokenizer;
	parser->token_i = 0;
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
