#include "minishell.h"

/* int	main(int ac, char **av, char **envp) */
/* { */
/* 	char		*command = av[1]; */
/* 	t_parser	*parser; */
/* 	int			last_err; */

/* 	(void ) ac;; */
/* 	last_err = 66; */
/* 	printf("\nThe command : %s\n\n", command); */
/* 	parser = parse_string(command, last_err); */
/* 	if (parser->error.error != 0) */
/* 	{ */
/* 		if (parser->error.error == 1) */
/* 			printf("bash : syntax error near unexpected token `%c`\n", parser_get_error_char(parser)); */
/* 		else */
/* 			printf("Error %d\n", parser->error.error); */
/* 	} */
/* 	else */
/* 		commands_print(parser->commands); */
/* 	/1* int i = 0; *1/ */
/* 	/1* t_command *cmd = NULL; *1/ */
/* 	/1* while (i < commands_get_size(parser->commands)) *1/ */
/* 	/1* { *1/ */
/* 	/1* 	printf("i : %d\n", i); *1/ */
/* 	/1* 	cmd = commands_get_i(parser->commands, i); *1/ */
/* 	/1* 	printf("Command %s\n", command_get_name(cmd)); *1/ */
/* 	/1* 	i++; *1/ */
/* 	/1* } *1/ */
/* 	last_err = pipex_launch(parser->commands, envp); */
/* 	parser_destroy(parser); */
/* 	return (0); */
/* } */

int	main(int ac, char **av, char **envp)
{
	char		*command;
	t_parser	*parser;
	int			last_err;

	last_err = 66;
	while (1)
	{
		command = readline("$> ");
		add_history(command);
		if (!command)
		{
			printf("Left\n");
			return (1);
		}
		/* printf("\nThe command : %s\n\n", command); */
		parser = parse_string(command, last_err);
		if (parser_get_error(parser) != 0)
			printf("Error %d\n", parser_get_error(parser));
		/* else */
			/* commands_print(parser->commands); */

		last_err = pipex_launch(parser->commands, envp);
		parser_destroy(parser);
		free(command);
	}
	rl_clear_history();
	return (0);
}
