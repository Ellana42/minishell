#ifndef PARSING_H
# define PARSING_H

# include "parser/parser.h"

t_parser	*parse_string(char *str, int last_err);
void		parser_destroy(t_parser *parser);
int			parser_get_error(t_parser *parser);
int			parser_get_error_char(t_parser *parser);

#endif
