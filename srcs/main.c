#include "minishell.h"

int t_glob;

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

static void	handler(int sig, siginfo_t *si, void *ucontext)
{
	(void) si;
	(void) ucontext;
	(void) sig;
	if (sig == SIGINT)
	{
		// TODO stop all running programs and exit
		t_glob = 0;
	}
}

int	init_sa(sa *sa_c)
{
	sigemptyset(&sa_c->sa_mask);
	sa_c->sa_flags = SA_SIGINFO;
	sa_c->sa_sigaction = handler;
	sigaction(SIGINT, sa_c, NULL);
	sigaction(SIGQUIT, sa_c, NULL);
	sigaction(SIGTSTP, sa_c, NULL);
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	int	last_err;
	sa	sa_c;

	t_glob = 1;
	last_err = 0;
	init_sa(&sa_c);
	while (t_glob && last_err != -1)
		last_err = run_shell(last_err, envp);
	rl_clear_history();
	return (0);
}
