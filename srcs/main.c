#include "minishell.h"

t_glob	*g_glob;

int	run_shell(char **envp, int *last_err, t_minishell *minishell)
{
	char		*command;
	char		*expanded_command;
	t_parser	*parser;

	minishell_set_terminal(minishell, MINISHELL_TERMINAL);
	command = readline("$> ");
	minishell_set_terminal(minishell, BASE_TERMINAL);
	if (!command)
		return (1);
	if (*command != '\0')
		add_history(command);
	expanded_command = expand(command, glob_get_exit_status());
	if (!expanded_command)
	{
		*last_err = 1;
		return (0);
	}
	free(command);
	parser = parse(expanded_command, glob_get_exit_status());
	free(expanded_command);
	*last_err = parser_get_error(parser);
	if (*last_err == 0)
		*last_err = execution(parser, envp);
	parser_destroy(parser);
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	int			last_err;
	int			err;
	t_minishell	*minishell;

	(void )ac;
	(void )av;
	last_err = 0;
	err = 0;
	minishell = minishell_alloc();
	if (minishell_init(minishell, envp))
		return (1);
	if (glob_init(last_err, envp))
		return (1);
	while (glob_get_state() && !err)
	{
		err = run_shell(envp, &last_err, minishell);
		if (glob_get_exit_status() == -5)
		{
			last_err = 130;
			printf("\n");
		}
		glob_set_exit_status(last_err);
	}
	printf("exit\n");
	minishell_destroy(minishell);
	rl_clear_history();
	glob_destroy();
	return (last_err);
}
