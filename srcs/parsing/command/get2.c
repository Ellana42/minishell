/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:53:49 by mkaploun          #+#    #+#             */
/*   Updated: 2023/01/07 11:56:05 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

char	*command_get_name(t_command *command)
{
	return (command->command);
}

t_list	**command_get_args(t_command *command)
{
	return (command->args);
}

t_list	**command_get_out(t_command *command)
{
	return (command->out);
}

t_list	**command_get_outa(t_command *command)
{
	return (command->out_a);
}

t_list	**command_get_in(t_command *command)
{
	return (command->in);
}
