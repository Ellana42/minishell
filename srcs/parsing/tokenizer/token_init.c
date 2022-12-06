#include "token.h"

int	token_init_str(t_token *token, char *str, int index, char c)
{
	char	*dst;

	token->type = Str;
	token->str = NULL;
	dst = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!dst)
		return (1);
	str_cpy(str, dst);
	token->str = dst;
	token->current_index = index;
	token->current_char = c;
	return (0);
}

int	token_init_eol(t_token *token, int index, char c)
{
	char	*dst;

	token->type = Eol;
	token->str = NULL;
	token->current_index = index;
	token->current_char = c;
	return (0);
}

int	token_init_pipe(t_token *token, int index, char c)
{
	char	*dst;

	token->type = Pipe;
	token->str = NULL;
	token->current_index = index;
	token->current_char = c;
	return (0);
}

int	token_init_out(t_token *token, int index, char c)
{
	char	*dst;

	token->type = Out;
	token->str = NULL;
	token->current_index = index;
	token->current_char = c;
	return (0);
}

int	token_init_outa(t_token *token, int index, char c)
{
	char	*dst;

	token->type = Outa;
	token->str = NULL;
	token->current_index = index;
	token->current_char = c;
	return (0);
}

int	token_init_in(t_token *token, int index, char c)
{
	char	*dst;

	token->type = In;
	token->str = NULL;
	token->current_index = index;
	token->current_char = c;
	return (0);
}

int	token_init_ina(t_token *token, int index, char c)
{
	char	*dst;

	token->type = Ina;
	token->str = NULL;
	token->current_index = index;
	token->current_char = c;
	return (0);
}
