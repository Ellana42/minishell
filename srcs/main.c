#include "parsing/parsing.h"
#include "execution/pipex.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

int	main(int ac, char **av, char **envp)
{
	char		*command = av[1];
	t_parser	*parser;
	int			last_err;

	last_err = 66;
	printf("\nThe command : %s\n\n", command);
	parser = parse_string(command, last_err);
	if (parser->error.error != 0)
	{
		if (parser->error.error == 1)
			printf("bash : syntax error near unexpected token `%c`\n", parser_get_error_char(parser));
		else
			printf("Error %d\n", parser->error.error);
	}
	else
		commands_print(parser->commands);
	pipex_launch(parser->commands, envp);
	parser_destroy(parser);
	return (0);
}

/* int	main(int ac, char **av) */
/* { */
/* 	char		*command; */
/* 	t_parser	*parser; */
/* 	int			last_err; */

/* 	last_err = 66; */
/* 	while (1) */
/* 	{ */
/* 		command = readline("$> "); */
/* 		add_history(command); */
/* 		if (!command) */
/* 			return (1); */
/* 		printf("\nThe command : %s\n\n", command); */
/* 		parser = parse_string(command, last_err); */
/* 		if (parser_get_error(parser) != 0) */
/* 			printf("Error %d\n", parser_get_error(parser)); */
/* 		else */
/* 			commands_print(parser->commands); */

/* 		pipex(parser->commands); */
/* 		parser_destroy(parser); */
/* 		free(command); */
/* 	} */
/* 	rl_clear_history(); */
/* 	return (0); */
/* } */
