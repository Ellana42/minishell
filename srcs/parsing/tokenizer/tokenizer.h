#ifndef TOKENIZER_H
# define TOKENIZER_H

# include <stdio.h>
# include "../../../libft/includes/libft.h"
# include "token.h"

typedef enum s_state{Noquote = 0, Quote = 1, SingleQuote = 2} t_state;

typedef struct s_tokenizer{
	char *command;
	int	size;
	char *cmd_ptr;
	int	cmd_i;
	char *acc;
	char *acc_ptr;
	int acc_i;
	t_state state;
	t_list **tokens;
} t_tokenizer;

t_tokenizer	*tokenizer_alloc(void);
int tokenizer_init(t_tokenizer *tokenizer, char *cmd);
void tokenizer_dispose(t_tokenizer *tokenizer);
void tokenizer_free(t_tokenizer *tokenizer);
int tokenizer_move_cursor(t_tokenizer *tokenizer);
int tokenizer_move_accumulator(t_tokenizer *tokenizer);
int tokenizer_push_pipe(t_tokenizer *tokenizer);
int tokenizer_push_string(t_tokenizer *tokenizer);
char tokenizer_get_char(t_tokenizer *tokenizer);
char tokenizer_get_next_char(t_tokenizer *tokenizer, int s);
int tokenizer_eol(t_tokenizer *tokenizer);
void reset_acc(t_tokenizer *tokenizer);
int tokenizer_is_empty_acc(t_tokenizer *tokenizer);
int tokenizer_accumulate(t_tokenizer *tokenizer);

#endif
