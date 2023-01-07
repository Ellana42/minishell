/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:53:48 by mkaploun          #+#    #+#             */
/*   Updated: 2023/01/07 11:54:03 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executables.h"

t_executables	*executables_alloc(void)
{
	t_executables	*executables;

	executables = ft_lstinit();
	return (executables);
}

int	executables_init(t_execution *execution, t_commands *cmds)
{
	int				i;
	int				commands_size;
	t_command		*command;
	t_executable	*new_executable;
	t_list			*new_executable_list;

	i = 0;
	if (!execution->executables)
		return (1);
	commands_size = commands_get_size(cmds);
	while (i < commands_size)
	{
		command = commands_get_i(cmds, i);
		new_executable = executable_alloc();
		if (executable_init(execution, new_executable, command, i))
			return (1);
		new_executable_list = ft_lstnew((void *)new_executable);
		ft_lstadd_back(execution->executables, new_executable_list);
		i++;
	}
	return (0);
}
