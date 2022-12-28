#ifndef PARSER_H
# define PARSER_H

# include <stdio.h>
# include "../../../libft/includes/libft.h"
# include "../tokenizer/tokenizer.h"
# include "../tokenize/tokenize.h"
# include "../command/command.h"
# include "../commands/commands.h"
# include "../../glob.h"

typedef enum s_parser_state{
	pStart = 0,
	pParams = 1,
	pOut = 2,
	pOuta = 3,
	pIn = 4,
	pIna = 5
}	t_parser_state;

typedef enum s_parser_error{
	ParserNoError = 0,
	ParserTokError = 1,
	ParserSyntaxError = 2,
	ParserAllocError = 3,
	ParserNotTokenized = 4,
	ParserQuotesUnclosed = 5,
	ParserUnknownError = 6,
	ParserUninitialized = -1
}	t_parser_error;

typedef struct s_parser_err {
	t_parser_error	error;
	t_token			*err_token;
}	t_parser_err;

typedef struct s_parser{
	t_command		*command;
	t_commands		*commands;
	t_parser_state	state;
	t_tokenizer		*tokenizer;
	int				token_i;
	t_parser_err	error;
}	t_parser;

t_parser	*parser_alloc(void);
int			parser_init(t_parser *parser, char *str, int last_err);
void		_free_string(void *str);
void		_free_command(void *command);
void		parser_dispose(t_parser *parser);
void		jparser_free(t_parser *parser);
t_token		*parser_get_token(t_parser *parser);
void		parser_move_cursor(t_parser *parser);
int			parser_is_eol(t_parser *parser);
int			parse_tokens(t_parser *parser);
int			parser_tokenize_string(t_parser *parser);
int			parse_out(t_parser *parser);
int			parse_outa(t_parser *parser);
int			parse_in(t_parser *parser);
int			parse_ina(t_parser *parser);
t_parser	*parser_set_error(t_parser *parser, t_parser_error error);
int			parser_set_error_return(t_parser *parser, t_parser_error error);
void		parser_print_error_token(t_parser *parser);

#endif
