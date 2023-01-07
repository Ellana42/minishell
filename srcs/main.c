/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:51:55 by mkaploun          #+#    #+#             */
/*   Updated: 2023/01/07 11:51:59 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_glob	*g_glob;

int	run_shell(int *last_err, t_minishell *minishell)
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
	glob_set_exit_status(0);
	if (!expanded_command)
		return (set_errnum(last_err, 1, 0));
	free(command);
	parser = parse(expanded_command, glob_get_exit_status());
	free(expanded_command);
	*last_err = parser_get_error(parser);
	if (commands_get_size(parser->commands) > MAX_PIPES)
		*last_err = error_msg3("Too many pipes", 1);
	if (*last_err == 0)
		*last_err = execution(parser, minishell);
	parser_destroy(parser);
	return (0);
}

int	shell_loop(int *last_err, t_minishell *minishell)
{
	int			err;

	err = 0;
	err = run_shell(last_err, minishell);
	*last_err = glob_get_exit_status();
	return (err);
}

int	main(int ac, char **av, char **envp)
{
	int			last_err;
	t_minishell	*minishell;
	int			err;

	(void )av;
	last_err = 0;
	err = 0;
	if (ac > 1)
		return (error_msg3("Too many arguments", 1));
	minishell = minishell_alloc();
	if (minishell_init(minishell, envp))
		return (1);
	if (glob_init(last_err, envp))
		return (1);
	while (glob_get_state() && !err)
		err = shell_loop(&last_err, minishell);
	printf("exit\n");
	minishell_destroy(minishell);
	rl_clear_history();
	glob_destroy();
	return (last_err);
}
