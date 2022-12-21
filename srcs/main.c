#include "minishell.h"

t_glob *g_glob;

/* int    main(int ac, char **av, char **envp) */
/* { */
/*     char        *command = av[1]; */
/*     t_parser    *parser; */
/*     int            last_err; */

/*     (void ) ac;; */
/*     last_err = 66; */
/*     printf("\nThe command : %s\n\n", command); */
/*     parser = parse_string(command, last_err); */
/*     if (parser->error.error != 0) */
/*     { */
/*         if (parser->error.error == 1) */
/*             printf("bash : syntax error near unexpected token `%c`\n", parser_get_error_char(parser)); */
/*         else */
/*             printf("Error %d\n", parser->error.error); */
/*     } */
/*     else */
/*         commands_print(parser->commands); */
/*     /1* int i = 0; *1/ */
/*     /1* t_command *cmd = NULL; *1/ */
/*     /1* while (i < commands_get_size(parser->commands)) *1/ */
/*     /1* { *1/ */
/*     /1*     printf("i : %d\n", i); *1/ */
/*     /1*     cmd = commands_get_i(parser->commands, i); *1/ */
/*     /1*     printf("Command %s\n", command_get_name(cmd)); *1/ */
/*     /1*     i++; *1/ */
/*     /1* } *1/ */
/*     last_err = execution(parser->commands, envp); */
/*     parser_destroy(parser); */
/*     return (0); */
/* } */

int	run_shell(int last_err, char **envp)
{
	char		*command;
	t_parser	*parser;
	int			err;

	command = readline("$> ");
	if (!command)
		return (-1);
	add_history(command);
	if (!command)
		return (1);
	/* printf("\nThe command : %s\n\n", command); */
	parser = parse_string(command, last_err);
	if (parser_get_error(parser) != 0)
		printf("Error %d\n", parser_get_error(parser));
	/* else */
		/* commands_print(parser->commands); */

	err = execution(parser->commands, envp);
	parser_destroy(parser);
	free(command);
	return (err);
}

int	init_tty()
{
	int	fd;
	struct termios  config;

	fd = open("/dev/tty", O_RDWR | O_NOCTTY | O_NDELAY); // TODO check device and perms
	if (fd == -1) 
		return (-1);
	if(!isatty(fd))
	{
		close(fd);
		return (-1);
	}
	if(tcgetattr(fd, &config) < 0)
	{
		close(fd);
		return (-1);
	}
	config.c_lflag &= ~ECHOCTL;
	if (tcsetattr(0, 0, &config))
	{
		close(fd);
		return (-1);
	}
	return (fd);
}

int	main(int ac, char **av, char **envp)
{
	int	last_err;
	sa	sa_c;
	int	tty;

	last_err = 0;
	tty = init_tty();
	if (glob_init())
		return (1);
	if (tty == -1)
		return (1);
	init_sa(&sa_c);
	while (g_glob->activated && last_err != -1)
		last_err = run_shell(last_err, envp);
	rl_clear_history();
	close(tty);
	return (0);
}
