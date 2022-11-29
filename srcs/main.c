#include <stdio.h>
#include "libft/includes/libft.h"

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
} t_tokenizer;

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

int	tokenizer_push_pipe(t_tokenizer *tokenizer)
{
	printf("pipe\n");
	return (0);
}

int	tokenizer_push_string(t_tokenizer *tokenizer)
{
	printf("string : %s\n", tokenizer->acc);
	return (0);
}

int	tokenizer_eol(t_tokenizer *tokenizer)
{
	return (!(*(tokenizer->cmd_ptr)));
}

char tokenizer_get_char(t_tokenizer *tokenizer)
{
	return (*(tokenizer->cmd_ptr));
}

char tokenizer_get_next_char(t_tokenizer *tokenizer, int s)
{
	// TODO Gestion d'erreur 
	return ((tokenizer->cmd_ptr)[s]);
}

int	tokenizer_is_empty_acc(t_tokenizer *tokenizer)
{
	return (tokenizer->acc_i == 0);
}

int	tokenizer_move_cursor(t_tokenizer *tokenizer)
{
	(tokenizer->cmd_ptr)++;
	(tokenizer->cmd_i)++;
	return (0);
}

int	tokenizer_move_accumulator(t_tokenizer *tokenizer)
{
	(tokenizer->acc_ptr)++;
	(tokenizer->acc_i)++;
	return (0);
}

int	tokenizer_accumulate(t_tokenizer *tokenizer)
{
	*(tokenizer->acc_ptr) = *(tokenizer->cmd_ptr);
	tokenizer_move_cursor(tokenizer);
	tokenizer_move_accumulator(tokenizer);
	return (0);
}


int	tokenize_noquote(t_tokenizer *tokenizer)
{
	if (tokenizer_get_char(tokenizer) == '|' && tokenizer_is_empty_acc(tokenizer))
	{
		tokenizer_push_pipe(tokenizer);
		tokenizer_move_cursor(tokenizer);
		return (0);
	}
	if (tokenizer_get_char(tokenizer) == '|')
	{
		tokenizer_push_string(tokenizer);
		reset_acc(tokenizer);
		tokenizer_push_pipe(tokenizer);
		tokenizer_move_cursor(tokenizer);
		return (0);
	}
	if (tokenizer_get_char(tokenizer) == ' ' && tokenizer_is_empty_acc(tokenizer))
	{
		tokenizer_move_cursor(tokenizer);
		return (0);
	}
	if (tokenizer_get_char(tokenizer) == ' ')
	{
		tokenizer_push_string(tokenizer);
		reset_acc(tokenizer);
		tokenizer_move_cursor(tokenizer);
		return (0);
	}
	tokenizer_accumulate(tokenizer);
	return (0);
}

int	tokenize(t_tokenizer *tokenizer)
{
	if (tokenizer->state == Quote)
	{
	}
	else if (tokenizer->state == Noquote)
	{
		tokenize_noquote(tokenizer);
	}
	else if (tokenizer->state == SingleQuote)
	{

	}
	return (0);
}

int	main(void)
{
	t_tokenizer tokenizer;
	char command[7] = "ls |la";
	printf("The command : %s\n", command);
	
	tokenizer_init(&tokenizer, command);
	while (!tokenizer_eol(&tokenizer))
	{
		tokenize(&tokenizer);
	}
	if (!tokenizer_is_empty_acc(&tokenizer))
		tokenizer_push_string(&tokenizer);
}
