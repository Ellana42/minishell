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
	tokenizer->acc = (char *)malloc(sizeof(char) * (tokenizer->size + 1));
	reset_acc(tokenizer);
	tokenizer->state = Noquote;
	return (0); // errors
}

void tokenizer_dispose(t_tokenizer *tokenizer)
{
	free(tokenizer->command);
	free(tokenizer->acc);
}

void tokenizer_free(t_tokenizer *tokenizer)
{
	free(tokenizer);
}
