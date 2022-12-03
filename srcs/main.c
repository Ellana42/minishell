#include "parsing/parsing.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

int	main(int ac, char **av)
{
	char *command;
	t_parser *parser;

	while (1)
	{
		command = readline("minishell -> ");
		add_history(command);
		if (!command)
			return (1);
		printf("\nThe command : %s\n\n", command);

		parser = parse_string(command);
		if (parser_get_error(parser) != 0)
			printf("Error %d\n", parser_get_error(parser));
		else
			commands_print(parser->commands);
		parser_destroy(parser);
		free(command);
	}
	rl_clear_history();
	return (0);
}
