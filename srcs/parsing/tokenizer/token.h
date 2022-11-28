#ifndef TOKEN_H
# define TOKEN_H

# include "../../../libft/includes/libft.h"

typedef enum s_token_type{Str = 0, Pipe = 1}	t_token_type;

typedef struct s_token{
	t_token_type	type;
	char			*str;
}	t_token;

t_token	*token_alloc(void);
int		token_init(t_token *token, t_token_type type, char *str);
void	token_dispose(t_token *token);
void	token_free(t_token *token);
/* void	token_destroy(t_token *token); */
void	token_destroy(void *token);

#endif
