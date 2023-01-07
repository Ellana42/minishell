/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:53:50 by mkaploun          #+#    #+#             */
/*   Updated: 2023/01/07 11:56:06 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

void	_command_print(void *command)
{
	command_print((t_command *)command);
}

void	commands_print(t_commands *commands)
{
	ft_lstiter(*commands, &_command_print);
}
