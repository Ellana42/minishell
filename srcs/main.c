#include "minishell.h"

t_glob	*g_glob;

int	init_term(void)
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
	rl_catch_signals = 0;
	config.c_lflag &= ~ECHOCTL;
	signal(SIGINT, &signal_ctrl_c);
	signal(SIGQUIT, &signal_ctrl_slash);
	if (tcsetattr(0, 0, &config))
	{
		close(fd);
		return (-1);
	}
	return (fd);
}

int	run_shell(char **envp, int *last_err)
{
	char		*command;
	char		*expanded_command;
	t_parser	*parser;

	command = readline("$> ");
	if (!command)
		return (1);
	add_history(command);
	if (!command)
		return (1);
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
	int		last_err;
	int		err;
	int		term;

	(void )ac;
	(void )av;
	last_err = 0;
	err = 0;
	term = init_term();
	if (term == -1)
		return (1);
	if (glob_init(last_err, envp))
		return (1);
	while (glob_get_state() && !err)
	{
		err = run_shell(envp, &last_err);
		glob_set_exit_status(last_err);
	}
	printf("exit\n");
	rl_clear_history();
	glob_destroy();
	close(term);
	return (last_err);
}
