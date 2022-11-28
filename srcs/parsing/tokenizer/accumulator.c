#include "tokenizer.h"

void	reset_acc(t_tokenizer *tokenizer)
{
	int	i;
	
	i = 0;
	while (i < tokenizer->size)
	{
		(tokenizer->acc)[i] = '\0';
		i++;
	}
	tokenizer->acc_i = 0;	
	tokenizer->acc_ptr = tokenizer->acc;
}

int	tokenizer_is_empty_acc(t_tokenizer *tokenizer)
{
	return (tokenizer->acc_i == 0);
}

int	tokenizer_accumulate(t_tokenizer *tokenizer)
{
	*(tokenizer->acc_ptr) = *(tokenizer->cmd_ptr);
	tokenizer_move_cursor(tokenizer);
	tokenizer_move_accumulator(tokenizer);
	return (0);
}

int	tokenizer_acc_concat(t_tokenizer *tokenizer, char *str)
{
	char	*tmp;
	size_t len_acc;

	if (!str)
		return (0);
	len_acc = ft_strlen(tokenizer->acc);
	tokenizer->acc_size += ft_strlen(str);
	tmp = (char *)malloc(sizeof(char) * (tokenizer->acc_size + 1)); // TODO check malloc
	ft_strlcpy(tmp, tokenizer->acc, len_acc + 1);	
	free(tokenizer->acc);
	ft_strlcat(tmp, str, tokenizer->acc_size + 1);
	tokenizer->acc = tmp;
	tokenizer->acc_i += ft_strlen(str);
	tokenizer->acc_ptr = &(tokenizer->acc[tokenizer->acc_i]);
	return (0);
}
