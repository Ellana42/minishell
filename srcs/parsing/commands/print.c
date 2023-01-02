/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:10:45 by mkaploun          #+#    #+#             */
/*   Updated: 2023/01/02 18:10:45 by mkaploun         ###   ########.fr       */
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
