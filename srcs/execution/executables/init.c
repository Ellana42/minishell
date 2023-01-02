/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellana <mtmrkaploun@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:02:48 by ellana            #+#    #+#             */
/*   Updated: 2023/01/02 18:02:58 by ellana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executables.h"

t_executables	*executables_alloc(void)
{
	t_executables	*executables;

	executables = ft_lstinit();
	return (executables);
}

int	executables_init(t_executables *executables, t_commands *cmds, int **pipes)
{
	int				i;
	int				commands_size;
	t_command		*command;
	t_executable	*new_executable;
	t_list			*new_executable_list;

	i = 0;
	if (!executables)
		return (1);
	commands_size = commands_get_size(cmds);
	while (i < commands_size)
	{
		command = commands_get_i(cmds, i);
		new_executable = executable_alloc();
		if (executable_init(new_executable, command, pipes, i)) // TODO accept error
			return (1);
		new_executable_list = ft_lstnew((void *)new_executable);
		ft_lstadd_back(executables, new_executable_list);
		i++;
	}
	return (0);
}
