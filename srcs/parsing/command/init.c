/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:10:41 by mkaploun          #+#    #+#             */
/*   Updated: 2023/01/02 18:10:41 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

t_command	*command_alloc(void)
{
	t_command	*command;

	command = (t_command *)malloc(sizeof(t_command));
	return (command);
}

int	command_init(t_command *command, char *cmd)
{
	char	*cmd_cpy;

	if (!cmd)
		cmd_cpy = NULL;
	else
	{
		cmd_cpy = (char *)malloc(sizeof(char) * (ft_strlen(cmd) + 1));
		if (!cmd_cpy)
			return (1);
		str_cpy(cmd, cmd_cpy);
	}
	command->command = cmd_cpy;
	command->args = ft_lstinit();
	command->out = ft_lstinit();
	command->in = ft_lstinit();
	if (!command->args || !command->out || !command->in)
		return (1);
	return (0);
}
