#ifndef PARSER_H
# define PARSER_H

# include <stdio.h>
# include "../../../libft/includes/libft.h"
# include "../tokenizer/tokenizer.h"
# include "../command/command.h"

typedef enum s_parser_state{pStart = 0, pParams = 1, pOut = 2, pOuta = 3, pIn = 4, pIna = 5} t_parser_state;

typedef struct s_parser{
	t_command		*command;
	t_list			**commands;
	t_parser_state	state;
	t_tokenizer		*tokenizer;
	int				*token_i;
} t_parser;

t_parser	*parser_alloc(void);
int	parser_init(t_parser *parser, t_tokenizer *tokenizer);
void	_free_string(void *str);
void	_free_command(void *command);
void parser_dispose(t_parser *parser);
void parser_free(t_parser *parser);
void	parser_destroy(t_parser *parser);

#endif
