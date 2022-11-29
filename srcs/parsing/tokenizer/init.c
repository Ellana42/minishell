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

	// TODO mallocs rate
	tokenizer->size = ft_strlen(cmd);
	cmd_cpy = (char *)malloc(sizeof(char) * (tokenizer->size + 1));
	ft_strlcpy(cmd_cpy, cmd, tokenizer->size + 1);
	tokenizer->command = cmd_cpy;
	tokenizer->cmd_ptr = tokenizer->command;
	tokenizer->cmd_i = 0;
	tokenizer->acc = acc_alloc();
	acc_init(tokenizer->acc, tokenizer->size);
	tokenizer->acc_var = acc_alloc();
	acc_init(tokenizer->acc_var, tokenizer->size);
	tokenizer->state = NoQuote;
	tokenizer->tokens = ft_lstinit();
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
