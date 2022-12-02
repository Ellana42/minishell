#include "tokenizer.h"

t_tokenizer	*tokenizer_alloc(void)
{
	t_tokenizer	*tokenizer;

	tokenizer = (t_tokenizer *)malloc(sizeof(t_tokenizer));
	return (tokenizer);
}

int	tokenizer_init(t_tokenizer *tokenizer, char *cmd)
{
	char	*cmd_cpy;

	tokenizer->size = ft_strlen(cmd);
	cmd_cpy = (char *)malloc(sizeof(char) * (tokenizer->size + 1));
	tokenizer->acc = acc_alloc();
	tokenizer->acc_var = acc_alloc();
	if (!cmd_cpy || !tokenizer->acc || !tokenizer->acc_var)
		return (1);
	ft_strlcpy(cmd_cpy, cmd, tokenizer->size + 1);
	tokenizer->command = cmd_cpy;
	tokenizer->cmd_ptr = tokenizer->command;
	tokenizer->cmd_i = 0;
	if (acc_init(tokenizer->acc, tokenizer->size))
		return (1);
	if (acc_init(tokenizer->acc_var, tokenizer->size))
		return (1);
	tokenizer->state = NoQuote;
	tokenizer->tokens = ft_lstinit();
	if (!tokenizer->tokens)
		return (1);
	return (0); // errors
}

void tokenizer_dispose(t_tokenizer *tokenizer)
{
	free(tokenizer->command);
	acc_destroy(tokenizer->acc);
	acc_destroy(tokenizer->acc_var);
	ft_lstclear(tokenizer->tokens, &token_destroy); // TODO cast (void *)token_destroy(void *)
	free(tokenizer->tokens);
}

void tokenizer_free(t_tokenizer *tokenizer)
{
	free(tokenizer);
}

void	tokenizer_destroy(t_tokenizer *tokenizer)
{
	tokenizer_dispose(tokenizer);
	tokenizer_free(tokenizer);
}
