#ifndef PARSER_H
# define PARSER_H

# include <stdio.h>
# include "../../../libft/includes/libft.h"
# include "../tokenizer/tokenizer.h"

typedef enum s_parser_state{pStart = 0, pParams = 1, pOut = 2, pOuta = 3, pIn = 4, pIna = 5} t_parser_state;

typedef struct s_parser{
	t_list			*cmd;
	t_list			**cmds;
	t_parser_state	state;
	t_tokenizer		*tokenizer;
	t_token			*current_token;
} t_parser;

#endif
