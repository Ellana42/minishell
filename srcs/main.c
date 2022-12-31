#include "minishell.h"

t_glob	*g_glob;

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
/*             printf("bash : syntax error near unexpected token `%c`\n", 
 *             parser_get_error_char(parser)); */
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

int	run_shell(char **envp, int *last_err)
{
	char		*command;
	t_parser	*parser;

	command = readline("$> ");
	if (!command)
		return (1);
	add_history(command);
	if (!command)
		return (1);
	parser = parse(command, glob_get_exit_status());
	*last_err = parser_get_error(parser);
	if (*last_err == 0)
		*last_err = execution(parser, envp);
	parser_destroy(parser);
	free(command);
	return (0);
}

// TODO check device and perms
int	init_tty(void)
{
	int				fd;
	struct termios	config;

	fd = open("/dev/tty", O_RDWR | O_NOCTTY | O_NDELAY);
	if (fd == -1)
		return (-1);
	if (!isatty(fd))
	{
		close(fd);
		return (-1);
	}
	if (tcgetattr(fd, &config) < 0)
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
	int		last_err;
	t_sa	sa_c;
	int		tty;
	int		err;

	last_err = 0;
	err = 0;
	tty = init_tty();
	if (tty == -1)
		return (1);
	if (glob_init(last_err, envp))
		return (1);
	init_sa(&sa_c);
	while (glob_get_state() && !err)
	{
		err = run_shell(envp, &last_err);
		glob_set_exit_status(last_err);
	}
	rl_clear_history();
	close(tty);
	glob_destroy();
	return (last_err);
}
