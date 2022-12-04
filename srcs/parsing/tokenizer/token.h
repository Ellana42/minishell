#ifndef TOKEN_H
# define TOKEN_H

# include "../../../libft/includes/libft.h"
# include "../utils/utils.h"

typedef enum s_token_type{
	Str = 0,
	Pipe = 1,
	Out = 2,
	Outa = 3,
	In = 4,
	Ina = 5,
	Eol = 6
}	t_token_type;


typedef struct s_token{
	t_token_type	type;
	char			*str;
}	t_token;

t_token	*token_alloc(void);
int		token_init(t_token *token, t_token_type type, char *str);
void	token_dispose(t_token *token);
void	token_free(t_token *token);
void	token_destroy(void *token);
void	token_print(t_token *token);

#endif
