#ifndef TOKENIZE_H
# define TOKENIZE_H

# include "../tokenizer/tokenizer.h"

int	tokenize_noquote(t_tokenizer *tokenizer);
int	tokenize_noquotev(t_tokenizer *tokenizer);
int	tokenize_quote(t_tokenizer *tokenizer);
int	tokenize_quotev(t_tokenizer *tokenizer);
int	tokenize_single_quote(t_tokenizer *tokenizer);
int	tokenize(t_tokenizer *tokenizer);

#endif
