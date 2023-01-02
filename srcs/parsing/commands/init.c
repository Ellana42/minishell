/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:10:45 by mkaploun          #+#    #+#             */
/*   Updated: 2023/01/02 18:10:45 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

t_commands	*commands_alloc(void)
{
	t_commands	*commands;

	commands = ft_lstinit();
	return (commands);
}

int	commands_init(t_commands *commands)
{
	(void )commands;
	return (0);
}

void	_free_command(void *command)
{
	command_destroy((t_command *)command);
}
