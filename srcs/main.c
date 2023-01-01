#include "minishell.h"

t_glob	*g_glob;

int	run_shell(char **envp, int *last_err)
{
	char		*command;
	char		*expanded_command;
	t_parser	*parser;

	set_signals_interactive();
	command = readline("$> ");
	set_signals_noninteractive();
	if (!command)
		return (1);
	add_history(command);
	if (!command)
		return (1);
	expanded_command = expand(command, glob_get_exit_status());
	if (!expanded_command)
	{
		printf("minishell: error during variable expansion\n");
		return (1);
	}
	free(command);
	parser = parse(expanded_command, glob_get_exit_status());
	*last_err = parser_get_error(parser);
	if (*last_err == 0)
		*last_err = execution(parser, envp);
	parser_destroy(parser);
	free(expanded_command);
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	int		last_err;
	t_sa	sa_c;
	int		err;

	(void )ac;
	(void )av;
	last_err = 0;
	err = 0;
	if (glob_init(last_err, envp))
		return (1);
	init_sa(&sa_c);
	while (glob_get_state() && !err)
	{
		err = run_shell(envp, &last_err);
		glob_set_exit_status(last_err);
	}
	rl_clear_history();
	glob_destroy();
	return (last_err);
}
