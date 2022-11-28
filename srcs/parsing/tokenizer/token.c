#include "token.h"

t_token	*token_alloc(void)
{
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	return (token);
}

int	token_init(t_token *token, t_token_type type, char *str)
{
	char	*str_cpy;
	size_t		size;

	size = 0;
	token->type = type;
	token->str = NULL;
	if (token->type == Str)
	{
		size = ft_strlen(str);
		str_cpy = (char *)malloc(sizeof(char) * (size + 1));
		token->str = str_cpy;
	}
	return (0); // TODO errors
}

void token_dispose(t_token *token)
{
	free(token->str);
}

void token_free(t_token *token)
{
	free(token);
}

void	token_destroy(void *token)
{
	token_dispose((t_token *)token);
	token_free((t_token *)token);
}
