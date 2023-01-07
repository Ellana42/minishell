/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:52:38 by mkaploun          #+#    #+#             */
/*   Updated: 2023/01/07 11:52:44 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	execution_is_builtin(t_execution *execution)
{
	char	*command_name;

	command_name = command_get_name(execution_get_current_command(execution));
	if (!ft_strncmp(command_name, "echo", 5))
		return (1);
	if (!ft_strncmp(command_name, "exit", 5))
		return (2);
	if (!ft_strncmp(command_name, "env", 4))
		return (3);
	if (!ft_strncmp(command_name, "cd", 3))
		return (4);
	if (!ft_strncmp(command_name, "pwd", 4))
		return (5);
	if (!ft_strncmp(command_name, "export", 7))
		return (6);
	if (!ft_strncmp(command_name, "unset", 6))
		return (7);
	return (0);
}

int	call_builtin(char **args_table, int command_number)
{
	int			err;

	err = 0;
	if (command_number == 1)
		err = builtin_echo(args_table);
	if (command_number == 2)
		err = builtin_exit(args_table);
	if (command_number == 3)
		err = env(args_table);
	if (command_number == 4)
		err = cd(args_table);
	if (command_number == 5)
		err = pwd_builtin(args_table);
	if (command_number == 6)
		err = builtin_export(args_table);
	if (command_number == 7)
		err = unset(args_table);
	return (err);
}

int	execution_launch_builtin(t_execution *execution)
{
	int			command_number;
	t_command	*command;
	char		**args_table;
	int			err;

	command_number = execution_is_builtin(execution);
	command = execution_get_current_command(execution);
	args_table = command_get_args_table(command);
	err = call_builtin(args_table, command_number);
	free(args_table);
	return (err);
}

int	execution_launch_builtin_single(t_execution *execution)
{
	t_executable	*executable;
	int				fd[2];
	int				err;
	int				dup_std[2];

	err = 0;
	executable = execution_get_current(execution);
	executable_get_fds_close(executable, fd);
	execution_close_unused(execution, execution->executable_index);
	if (fd[0] == -1 || fd[1] == -1)
		return (1);
	dup_std[0] = dup(STDIN_FILENO);
	dup_std[1] = dup(STDOUT_FILENO);
	if (execution_dup_in(fd[0]) || execution_dup_out(fd[1]))
		return (1);
	err = execution_launch_builtin(execution);
	close(fd[0]);
	close(fd[1]);
	if (execution_dup_in(dup_std[0]))
		return (1);
	if (execution_dup_out(dup_std[1]))
		return (1);
	close(dup_std[0]);
	close(dup_std[1]);
	return (err);
}
