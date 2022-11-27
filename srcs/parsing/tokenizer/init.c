#include "tokenizer.h"

int	tokenizer_init(t_tokenizer *tokenizer, char *cmd)
{
	tokenizer->command = cmd;
	tokenizer->size = ft_strlen(cmd);
	tokenizer->cmd_ptr = tokenizer->command;
	tokenizer->cmd_i = 0;
	tokenizer->acc = (char *)malloc(sizeof(char) * (tokenizer->size + 1));
	reset_acc(tokenizer);
	tokenizer->state = Noquote;
	return (0); // errors
}
