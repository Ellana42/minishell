#ifndef PARSING_H
# define PARSING_H

#include "parser/parser.h"

t_parser	*parse_string(char *str);
void	parser_destroy(t_parser *parser);

#endif
