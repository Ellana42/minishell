#ifndef TOKENIZER_H
# define TOKENIZER_H

# include <stdio.h>
# include "../../../libft/includes/libft.h"
# include "token.h"
# include "../accumulator/accumulator.h"

// NoQuote -> Quote, NoQuoteV, SingleQuote
// Quote -> NoQuote, QuoteV
// SingleQuote -> NoQuote
// NoQuoteV -> NoQuote
// QuoteV -> Quote
typedef enum s_state{
	NoQuote = 0,
	Quote = 1,
	SingleQuote = 2,
	NoQuoteV = 3,
	QuoteV = 4
}	t_state;

typedef struct s_tokenizer{
	char	*command;
	size_t	size;
	char	*cmd_ptr;
	int		cmd_i;
	t_acc	*acc;
	t_acc	*acc_var;
	t_state	state;
	t_list	**tokens;
}	t_tokenizer;

t_tokenizer	*tokenizer_alloc(void);
int			tokenizer_init(t_tokenizer *tokenizer, char *cmd);
void		tokenizer_dispose(t_tokenizer *tokenizer);
void		tokenizer_free(t_tokenizer *tokenizer);
int			tokenizer_move_cursor(t_tokenizer *tokenizer);
int			tokenizer_move_accumulator(t_tokenizer *tokenizer);
int			tokenizer_push_pipe(t_tokenizer *tokenizer);
int			tokenizer_push_string(t_tokenizer *tokenizer);
char		tokenizer_get_char(t_tokenizer *tokenizer);
char		tokenizer_get_next_char(t_tokenizer *tokenizer, int s);
int			tokenizer_eol(t_tokenizer *tokenizer);
void		reset_acc(t_tokenizer *tokenizer);
int			tokenizer_is_empty_acc(t_tokenizer *tokenizer);
int			tokenizer_accumulate(t_tokenizer *tokenizer);
void		tokenizer_print_tokens(t_tokenizer *tokenizer);
int			tokenizer_acc_concat(t_tokenizer *tokenizer, char *str);
int			tokenizer_push_out(t_tokenizer *tokenizer);
int			tokenizer_push_outa(t_tokenizer *tokenizer);
int			tokenizer_push_in(t_tokenizer *tokenizer);
int			tokenizer_push_ina(t_tokenizer *tokenizer);
int			tokenizer_push_eol(t_tokenizer *tokenizer);
int			tokenize_noquotev(t_tokenizer *tokenizer);
int			tokenizer_accumulate_var(t_tokenizer *tokenizer);
void		reset_acc_var(t_tokenizer *tokenizer);
int			tokenizer_is_empty_acc_var(t_tokenizer *tokenizer);
t_token		*tokenizer_get_token(t_tokenizer *tokenizer, int i);
void		tokenizer_destroy(t_tokenizer *tokenizer);

#endif
